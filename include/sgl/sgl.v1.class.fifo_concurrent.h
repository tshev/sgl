#pragma once
namespace sgl {
namespace v1 {

template<typename Q>
class fifo_concurrent {
    Q queue_;
    mutable std::shared_mutex* shared_mutex_;

public:
    fifo_concurrent() = default;
    fifo_concurrent(Q queue, std::shared_mutex* shared_mutex) : queue_(queue), shared_mutex_(shared_mutex) {}

    bool empty() const {
        std::lock_guard<std::shared_mutex> lock(*shared_mutex_);
        return queue_.empty();
    }

    template<typename F>
    bool pop_front(F function) {
        std::lock_guard lock(*shared_mutex_);
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
        std::lock_guard lock(*shared_mutex_);
        return queue_.push_back(x);
    }

    bool push_back(const char* data, uint64_t size) {
        std::lock_guard lock(*shared_mutex_);
        return queue_.push_back(data, size);
    }

    uint64_t size() const {
        std::lock_guard lock(*shared_mutex_);
        return queue_.size();
    }
};

} // namespace v1
} // namespace sgl
