#pragma once

namespace sgl {
namespace v1 {

struct fifo_storage {
    sgl::v1::mmap<char> data_;
    spinlock* shared_mutex_;
    std::atomic<uint8_t>* state_;
    std::atomic<uint8_t>* count_;
    sgl::v1::concurrent_circular_fifo<sgl::v1::circular_fifo_view<uint64_t>> fifo_;

public:

    fifo_storage(const char* path, uint64_t size) : data_(sgl::v1::fmmap<char>(path, size)),
                                                    shared_mutex_((spinlock*)data_.begin()), 
                                                    state_((std::atomic<uint8_t>*)(data_.begin() + sizeof(spinlock))),
                                                    count_((std::atomic<uint8_t>*)(data_.begin() + sizeof(spinlock) + 1)),
                                                    fifo_(sgl::v1::circular_fifo_view(data_.begin() + sizeof(spinlock) + 2ul, size - sizeof(spinlock) - 2ul), shared_mutex_) {
        init();
    }
    fifo_storage(const char* path) : data_(sgl::v1::fmmap<char>(path)),
                                     shared_mutex_((spinlock*)data_.begin()), 
                                     state_((std::atomic<uint8_t>*)(data_.begin() + sizeof(spinlock))),
                                     count_((std::atomic<uint8_t>*)(data_.begin() + sizeof(spinlock) + 1)),
                                     fifo_(sgl::v1::circular_fifo_view(data_.begin() + sizeof(spinlock) + 2ul, data_.size() - sizeof(spinlock) - 2ul), shared_mutex_) {
        init();
    }

    fifo_storage(const std::string& path, uint64_t size) : fifo_storage(path.data(), size) {}

    fifo_storage(const std::string& path) : fifo_storage(path.data()) {}
    fifo_storage(fifo_storage&&) = default;

    void init() {
        auto count = count_->fetch_add(1u);
        if (count == 0u) {
            if (state_->load() == 1ul) {
                std::cerr << "Waiting for destruction\n";
                while (state_->load() == 1ul); // wait for destructuction before the recreation
            }
            sgl::v1::construct_at(shared_mutex_);
            state_->store(1ul);
        } else {
            if (state_->load() == 0) {
                std::cerr << "Waiting for construction\n";
                while (state_->load() == 0);  // can't the object use before it was initialized
            }
        }
    }

    template<typename T>
    bool push_back(T x) {
        return fifo_.push_back(x); 
    }

    template<typename T>
    bool push_back(const std::string& x) {
        return fifo_.push_back(x.data(), x.size());
    }

    bool push_back(const char* data, uint64_t size) {
        return fifo_.push_back(data, size);
    }

    bool write(const std::string& x) {
        return push_back(x);
    }

    void flush() {
        data_.sync_data();
    }

    template<typename F>
    bool pop_front(F f) {
        return fifo_.pop_front(f);
    }

    uint64_t size() const {
        return fifo_.size();
    }

    void stop() {
        this->~fifo_storage();
    }

    bool empty() const {
        return fifo_.empty();
    }

    ~fifo_storage() {
        if (!data_.partially_formed() && --(*count_) == 0u) {
            std::destroy_at(shared_mutex_);
            state_->store(0u);
        }
    }
};

}
}
