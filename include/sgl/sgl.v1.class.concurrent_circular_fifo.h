#pragma once
namespace sgl {
namespace v1 {


/*
class spinlock {
    std::atomic_flag locked = ATOMIC_FLAG_INIT ;

public:
    void lock() {
        while (locked.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        locked.clear(std::memory_order_release);
    }
};
*/


template<typename Q>
class concurrent_circular_fifo {
    Q queue_;
    mutable sgl::v1::atomic_mutex_ptr<bool> shared_mutex_;

public:
    concurrent_circular_fifo() = default;
    concurrent_circular_fifo(Q queue, sgl::v1::atomic_mutex_ptr<bool> shared_mutex) : queue_(queue), shared_mutex_(shared_mutex) {}

    bool empty() const {
        std::lock_guard<atomic_mutex_ptr<bool>> lock(shared_mutex_);
        return queue_.empty();
    }

    template<typename F>
    bool pop_front(F function) {
        std::lock_guard<sgl::v1::atomic_mutex_ptr<bool>> lock(shared_mutex_);
        if (!queue_.empty()) {
            if (function(queue_.front())) {
                queue_.pop_front();
                return true;
            }
        }
        return false;
    }

    template<typename T>
    bool push_back(const T& x) {
        std::lock_guard<sgl::v1::atomic_mutex_ptr<bool>> lock(shared_mutex_);
        auto r = queue_.push_back(x);
        queue_.log();
        return r;
    }

    bool push_back(const char* data, uint64_t size) {
        std::lock_guard<sgl::v1::atomic_mutex_ptr<bool>> lock(shared_mutex_);
        auto r = queue_.push_back(data, size);
        queue_.log();
        return r;
    }

    uint64_t size() const {
        std::lock_guard<sgl::v1::atomic_mutex_ptr<bool>> lock(shared_mutex_);
        return queue_.size();
    }
};

} // namespace v1
} // namespace sgl
