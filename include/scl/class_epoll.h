#pragma once
// #include <sys/epoll.h>
namespace scl {
struct epoll_base {
    constexpr static int ctl_add = EPOLL_CTL_ADD;
    constexpr static int ctl_mod = EPOLL_CTL_MOD;
    constexpr static int ctl_del = EPOLL_CTL_DEL;
    constexpr static int in = EPOLLIN;
    constexpr static int out = EPOLLOUT;

    struct flag : sgl::totally_ordered<flag> {
        int value;

        flag() {}

        flag(int value) noexcept : value(value) {}

        flag(const flag& x) : value(x.value) {}

        flag& operator=(const flag& x) {
            value = x.value;
            return *this;
        }

        friend
        inline
        bool operator==(const flag& x, const flag& y) {
            return x.value == y.value;
        }

        friend
        inline
        bool operator!=(const flag& x, const flag& y) {
            return !(x == y);
        }

        friend
        inline
        bool operator<(const flag& x, const flag& y) {
            return x.value < y.value;
        }
        
    };
    struct event {
        struct epoll_event value;

        event() = default;

        event(uint32_t events) {
          value.events = events;
        }

        event(uint32_t events, int fd) {
          value.events = events;
          value.data.fd = fd;
        }

        bool epollin() const {
          return (value.events & scl::epoll_base::in) == scl::epoll_base::in;
        }

        bool epollout() const {
          return (value.events & scl::epoll_base::out) == scl::epoll_base::out;
        }

        bool epollrdhup() const {
          return (value.events & EPOLLRDHUP) == EPOLLRDHUP;
        }
    };
};

class epoll : public epoll_base {
    typedef int value_type;

    value_type file_descriptor_;

public:
    epoll() : epoll(0) {}

    epoll(int size) : file_descriptor_(epoll_create(size)) {
      if (file_descriptor_ == -1) {
        throw std::runtime_error("epoll::epoll(): " + std::to_string(errno));
      }

    }

    epoll(flag x) : file_descriptor_(epoll_create1(x.value)) {}

    ~epoll() {
        close(file_descriptor_);
    }

    epoll_base::event& ctl(int op, int fd, epoll_base::event& event) {
        int r = epoll_ctl(file_descriptor_, op, fd, &(event.value));
        if (r < 0) {
          throw std::runtime_error("epoll::ctl(int, int, epoll_base::event): " + std::to_string(errno));
        }
        return event;
   
    }

    epoll_base::event ctl(int op, int fd, int event_events) {
        epoll_base::event event(event_events, fd);
        ctl(op, fd, event);
        return event;
    }

    epoll_base::event ctl(int op, int fd) {
        epoll_base::event event(EPOLLIN, fd);
        ctl(op, fd, event);
        return event;
    }

    epoll_base::event ctl_add(int action, int fd, int events_events) {
      return ctl(epoll_base::ctl_add | action, fd, events_events);
    }

    template<typename ForwardIterator>
    size_t wait(ForwardIterator events, int max_n, int timeout) {
        static_assert(sizeof(ForwardIterator) == sizeof(void*), "invalid iterator");
        int r = epoll_wait(file_descriptor_, reinterpret_cast<epoll_event*>(&*events), max_n, timeout);
        if (r < 0) { throw std::runtime_error("epoll::wait" + std::to_string(errno)); }
        return r;
    }

    template<typename RandomAccessIterator>
    void operator()(RandomAccessIterator events, RandomAccessIterator events_last) {
        /*
        int n = static_cast<int>(events_last - events);
        struct epoll_event* events_converted = reinterpret_cast<struct epoll_event*>(&events[0]);

        int events_count = epoll.wait(value, events_converted, n, -1);
        if (nf_descriptor == -1) {
            throw std::runtime_error("epoll_wait");
        }
        for (int i = 0; i != events_count; ++i) {

        }*/

    }
};
} // namespace scl
