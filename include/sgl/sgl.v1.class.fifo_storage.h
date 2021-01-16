#pragma once

namespace sgl {
namespace v1 {

class state_lock {
    sgl::v1::atomic_mutex_ptr<bool> shared_mutex_;
    std::atomic<int8_t>* state_ = nullptr;
    std::atomic<int8_t>* count_ = nullptr;
public:
    static constexpr const size_t size = 3;

    state_lock() = default;

    template<typename Ostream>
    state_lock(char* data, Ostream& cerr) : shared_mutex_((std::atomic<bool>*)data),
                                            state_((std::atomic<int8_t>*)data + 1),
                                            count_((std::atomic<int8_t>*)data + 2) { 
        if (data != nullptr) {
            auto count = count_->fetch_add(1u);
            if (count == 0u) {
                if (state_->load() == 1ul) {
                    cerr << "Waiting for destruction\n";
                    while (state_->load() == 1ul) __builtin_ia32_pause(); // wait for destructuction before the recreation
                }
                state_->store(1ul);
            } else {
                if (state_->load() == 0) {
                    cerr << "Waiting for construction\n";
                    while (state_->load() == 0) __builtin_ia32_pause();  // can't the object use before it was initialized
                }
            }
        }
    }

    char* begin() {
        return (char*)shared_mutex_.data();
    }

    char* end() {
        return (char*)count_ + sizeof(count_);
    }

    auto& shared_mutex() {
        return shared_mutex_;
    }

    ~state_lock() {
        if (count_ != nullptr) {
            if (--(*count_) == 0u) {
                //std::destroy_at(shared_mutex_);
                state_->store(0u);
            }
        }
    }
};

struct fifo_storage {
    sgl::v1::mmap<char> data_;
    sgl::v1::state_lock state_lock_;
    sgl::v1::concurrent_circular_fifo<sgl::v1::circular_fifo_view<uint64_t>> fifo_;

public:
    fifo_storage(const char* path) : data_(sgl::v1::fmmap<char>(path)),
                                     state_lock_(data_.begin(), std::cerr)
                                     {
        //std::lock_guard lock(state_lock_.shared_mutex());
        fifo_ = sgl::v1::concurrent_circular_fifo<sgl::v1::circular_fifo_view<uint64_t>>(sgl::v1::circular_fifo_view(data_.begin() + state_lock::size, data_.size() - state_lock::size), state_lock_.shared_mutex());
    }


    fifo_storage(const char* path, uint64_t size) : data_(sgl::v1::fmmap<char>(path, size)), state_lock_(data_.begin(), std::cerr) {
        //std::lock_guard lock(state_lock_.shared_mutex());
        fifo_ = sgl::v1::concurrent_circular_fifo<sgl::v1::circular_fifo_view<uint64_t>>(sgl::v1::circular_fifo_view(data_.begin() + state_lock::size, data_.size() - state_lock::size), state_lock_.shared_mutex());
    }

    fifo_storage(const std::string& path) : fifo_storage(path.data()) {}

    fifo_storage(fifo_storage&&) = default;

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
};

}  // namespace v1
}  // namespace sgl
