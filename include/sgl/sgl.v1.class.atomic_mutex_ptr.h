#pragma once

namespace sgl {
namespace v1 {

template<typename T>
class atomic_mutex_ptr {
    mutable std::atomic<T>* lock_;
    size_t spin;
public:
    atomic_mutex_ptr() = default;

    atomic_mutex_ptr(std::atomic<T>* lock, size_t spin) : lock_(lock), spin(spin)  {}
    atomic_mutex_ptr(std::atomic<T>* lock) : atomic_mutex_ptr(lock, default_spin()) {}

    atomic_mutex_ptr(std::atomic<T>& lock, size_t spin) : atomic_mutex_ptr(&lock, spin) {}
    atomic_mutex_ptr(std::atomic<T>& lock) : atomic_mutex_ptr(&lock) {}

    atomic_mutex_ptr(const atomic_mutex_ptr&) = default;

    std::atomic<T>* data() {
        return lock_;
    }
    const std::atomic<T>* data() const {
        return lock_;
    }


    size_t default_spin() const noexcept {
        if (1u < std::thread::hardware_concurrency()) {
            return 2048ul;
        }
        return 1ul;
    }

    bool try_lock() const noexcept {
        return lock_->load(std::memory_order_relaxed) == T(0) && lock_->exchange(T(1), std::memory_order_acquire) == T(0);
    }

    void _lock_n() const {
        while (true) {
            if (try_lock()) {
                return;
            }

            for (size_t current_spin = 1ul; current_spin < spin; current_spin <<= 1ul) {
                for (size_t j = 0; j < current_spin; ++j) {
                    __builtin_ia32_pause();
                }
                if (try_lock()) {
                    return;
                }
            }
            sched_yield();
        }
    }

    void _lock_1() const {
        while (!try_lock());
    }

    void lock() const noexcept {
        if (1u < spin) {
            _lock_n();
        } else {
            _lock_1();
        }
        /*
        //Alternative implemntation 
        while (lock_->exchange(T(1), std::memory_order_acquire)) {
            while (lock_->load(std::memory_order_relaxed)) {
                __builtin_ia32_pause();
            }
        }
        */
    }

    void unlock() const noexcept {
        lock_->store(T(0), std::memory_order_release);
    }
};

} // namespace v1
} // namespace sgl
