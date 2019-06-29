#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sgl/sgl.h>
#include <sgl/class_epoll.h>

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
struct receive {
  int socket_file_descriptor;
  sockaddr* socket_address_ptr;

  int operator()(const sgl::epoll::event &single_event) {
      if (single_event.value.data.fd == socket_file_descriptor) {
        socklen_t addrlen = sizeof(*socket_address_ptr);
        int conn_sock = accept(single_event.value.data.fd, socket_address_ptr, &addrlen);
        if (conn_sock == -1) {
          perror("accept");
          return -1;
        }
        constexpr size_t k = 4096;
        char buffer[k];
        int n = read(conn_sock, buffer, k - 1);
        std::cout << "read " << n << " bytes\n";
        buffer[n] = '\0';
        std::cout << buffer << std::endl;

        std::string response = "HTTP/1.1 200 OK" \
                               "Date: Mon, 27 Jul 2009 12:28:53 GMT" \
                               "Server: Apache/2.2.14 (Win32)" \
                               "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT" \
                               "Content-Length: 88" \
                               "Content-Type: text/html" \
                               "Connection: Closed";
        std::cout << "resp\n";
        write(conn_sock, response.c_str(), respone.size());
      }
    
  }
};

struct ipv4socket_base {
  int socket_file_descriptor = -1;
  struct sockaddr_in socket_address;
  ~ipv4socket_base() {
      if (socket_file_descriptor > 0) {
        ::close(socket_file_descriptor);
      }
   }
};

struct ipv4socket : ipv4socket_base {

  ipv4socket(unsigned short port) {
    bzero((char *) &socket_address, sizeof(socket_address));

    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_file_descriptor < 0) {
      throw std::runtime_error("ipv4socket: creation error"); 
    }

    setnonblocking(socket_file_descriptor);
    int one = 1;
    setsockopt(socket_file_descriptor, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
    one = 1;
    setsockopt(socket_file_descriptor, SOL_SOCKET, SO_REUSEPORT, &one, sizeof(one));


    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = INADDR_ANY;
    socket_address.sin_port = htons(port);

    if (bind(socket_file_descriptor, (sockaddr*)&socket_address, sizeof(socket_address)) == -1) {
      throw std::runtime_error("ipv4socket: bind error"); 
    }
    if (::listen(socket_file_descriptor, 5) == -1) {
      std::cout << errno << std::endl;
    }

  }

  void listen(int timeout) {
  }

  int raw() {
      return socket_file_descriptor;
  }

  sockaddr* address() {
    return (sockaddr*)&socket_address;
  }
};

int main() {
    ipv4socket socket(8000);
    socket.listen(5);

    size_t initial_events_count = 100;
    std::vector<sgl::epoll::event> events(initial_events_count);
    sgl::epoll epoll(10);
    sgl::epoll::event event = epoll.ctl_add(0, socket.raw());
    int nfds = epoll.wait(std::begin(events), events.size(), -1);
    std::for_each(std::begin(events), std::begin(events) + nfds, receive{socket.raw(), socket.address()});

}
