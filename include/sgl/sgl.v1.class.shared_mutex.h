#pragma once
namespace sgl {
namespace v1 {
class shared_mutex {
    pthread_mutexattr_t mutexattr;
    pthread_mutex_t mutex;

public:

    shared_mutex()  {
        pthread_mutexattr_init(&mutexattr);
        pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(&mutex, &mutexattr);
    }

    shared_mutex(const shared_mutex&) = delete;

    void lock() {
        pthread_mutex_lock(&mutex);
    }

    void unlock() {
        pthread_mutex_unlock(&mutex);
    }
}; // class shared_mutex
} // namespace v1
} // namespace sgl
