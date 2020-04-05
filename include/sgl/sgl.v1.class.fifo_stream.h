#pragma once

namespace sgl {
namespace v1 {

struct fifo_stream {
    sgl::v1::mmap<char> data_;
    std::shared_mutex* shared_mutex_;
    std::atomic<uint8_t>* state_;
    std::atomic<uint8_t>* count_;
    sgl::v1::fifo_concurrent<sgl::v1::fifo_view<uint64_t>> fifo_;

public:

    fifo_stream(const char* path, uint64_t size) : data_(sgl::v1::fmmap<char>(path, size)),
                                                   shared_mutex_((std::shared_mutex*)data_.begin()), 
                                                   state_((std::atomic<uint8_t>*)(data_.begin() + sizeof(std::shared_mutex))),
                                                   count_((std::atomic<uint8_t>*)(data_.begin() + sizeof(std::shared_mutex) + 1)),
                                                   fifo_(sgl::v1::fifo_view(data_.begin() + sizeof(std::shared_mutex) + 2ul, size - sizeof(std::shared_mutex) - 2ul), shared_mutex_) {
        init();
    }

    void init() {
        auto count = count_->fetch_add(1u);
        if (count == 0u) {
            while (state_->load() == 1ul); // wait for destructuction before the recreation
            sgl::v1::construct_at(shared_mutex_);
            state_->store(1ul);
        } else {
            std::cerr << "Waiting\n";
            while (state_->load() == 0); // can't the object use before it was initialized
        }

    }

    template<typename T>
    bool push_back(T x) {
        return fifo_.push_back(x); 
    }

    template<typename F>
    bool pop_front(F f) {
        return fifo_.pop_front(f);
    }

    uint64_t size() const {
        return fifo_.size();
    }

    void stop() {
        this->~fifo_stream();
    }

    bool empty() const {
        return fifo_.empty();
    }

    ~fifo_stream() {
        if (--(*count_) == 0u) {
            std::destroy_at(shared_mutex_);
            state_->store(0u);
        }
    }
};

}
}
