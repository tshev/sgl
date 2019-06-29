#include <sys/socket.h>
#include <csignal>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sgl/sgl.h>
#include <scl/class_epoll.h>
#include <scl/class_socket.h>

#include <vector>
void setnonblocking(int sock) {
  int opts;
  opts = fcntl(sock, F_GETFL);

  if(opts < 0) {
    perror("fcntl(sock, GETFL)");
    exit(1);
  }

  opts = opts | O_NONBLOCK;

  if(fcntl(sock, F_SETFL, opts) < 0) {
    perror("fcntl(sock, SETFL, opts)");
    exit(1);
  }
}


int count;
int closed;
const char* str_log_info = "[LOG INFO] ";
namespace app {
template<typename Socket>
struct accept {
  typedef Socket socket_type;
  socket_type* socket;
  scl::epoll* epoll;

  accept(socket_type& socket, scl::epoll& epoll) : socket(&socket), epoll(&epoll) {}

  void operator()(const scl::epoll::event& event) {
    int event_fd = event.value.data.fd;
    //std::cout << str_log_info  << "[accept<S>::operator()] " << "[events.value.fd] " << "[" << event_fd << "]"  <<  std::endl;
    //std::cout << str_log_info <<  "[accept<S>::operator()] " << "[event.value.events == EPOLLOUT] [" << std::boolalpha << event.epollout() << "]" << std::endl;
    //std::cout << str_log_info <<  "[accept<S>::operator()] " << "[event.value.events == EPOLLIN] [" << std::boolalpha << event.epollin() << "]" << std::endl;

    if (event_fd == socket->raw()) {
      const auto [conn_sock, len] = socket->accept(event.value.data.fd);
      if (conn_sock < 0) {
        std::cout << "accept "  << conn_sock << " " << errno << std::endl;
      } else {
        epoll->ctl(EPOLL_CTL_ADD, conn_sock, EPOLLET | EPOLLIN);
      }
    } else {
      if (event.epollin()) {
        constexpr size_t len = 1000;
        int received = 0;
        while (true) {
          char buffer[len];
          int n = recv(event_fd, buffer, len - 1, MSG_DONTWAIT);
          if (n > 0) {
            buffer[n] = '\0';
            received += n;
          } else {
            std::cout << "BAD " << errno << std::endl;
            ++closed;
            close(event_fd);
            break;
          }
          if (n < len - 1) break;
        }
        if (received > 0) { 
          epoll->ctl(EPOLL_CTL_MOD, event_fd, EPOLLET | EPOLLOUT);
        }
      } else if (event.epollout()) {
        static std::string response = "HTTP/1.1 200 OK\n" \
                               "Connection: Closed\n\n1234567890";
        //std::cout << str_log_info <<  "[accept<S>::operator()] " << "[send]" << std::endl;
        int n = send(event_fd, response.c_str(), response.size(), MSG_DONTWAIT);
        if (n < 0) {
          throw std::runtime_error("Bad code");
        } else if (n == response.size()) {
          ++count;
          ++closed;
          epoll->ctl(EPOLL_CTL_DEL, event_fd, 0);
          close(event_fd);
        } else {
          throw std::runtime_error("Bad code");
        }
      } else {
        std::cout  << "Strange\n";
      }
    }
  }
};
}

void epoll_errors_help() {
  static thread_local std::vector<std::pair<std::string, int>> errors_epoll_ctl = {
    {"EBADF", EBADF},
    {"EEXIST", EEXIST},
    {"EINVAL", EINVAL},
    {"ENOENT", ENOENT},
    {"ENOMEM", ENOMEM},
    {"ENOSPC", ENOSPC},
    {"EPERM", EPERM}
  };
  for (const auto& x: errors_epoll_ctl) {
    std::cout << x.first << " " << x.second << std::endl;
  }
}
int gevents;

int main() {
    std::signal(SIGINT, [](int s) {
      std::cout << count << std::endl;
      std::cout << closed << std::endl;
      std::cout << gevents << std::endl;
    });

    typedef scl::server_socket<scl::ipv4, scl::tcp> ipv4socket;
    int listen_timeout = 0;
    ipv4socket socket(scl::ipv4::address(8000, "127.0.0.1"), listen_timeout);

    size_t len = 50;
    std::vector<scl::epoll::event> events(len);
    scl::epoll epoll(len);
    epoll.ctl_add(0, socket.raw(), scl::epoll_base::in);
    std::cout << str_log_info << "[listening socket] " << "[" << socket.raw() << "]"  << std::endl;

    app::accept<ipv4socket> accept(socket, epoll);
    try {
      for(;;) {
        size_t nfds = epoll.wait(std::begin(events), events.size(), -1);
        std::for_each(std::begin(events), std::begin(events) + nfds, accept);
        gevents += nfds;
      }
    } catch(const std::exception& exc) {
      std::cout << exc.what() << std::endl;
    }
}
