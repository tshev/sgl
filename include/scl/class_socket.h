namespace scl {
struct ipv6 {
  static constexpr int value = AF_INET6;
}; // struct ipv6

struct ipv4 {
  static constexpr int value = AF_INET;

  struct address {
    struct sockaddr_in value;

    address() {
      bzero((char *)&value, sizeof(value));
      value.sin_family = AF_INET;
    }

    address(in_port_t port) : address(port, INADDR_ANY) {}

    address(in_port_t port, uint32_t s_addr) {
      value.sin_family = AF_INET;
      value.sin_addr.s_addr = s_addr;
      value.sin_port = htons(port);
    }

    address(in_port_t port, const char* ip) :
        address(port, ::inet_addr(ip)) {}

    // address(in_port_t port, uint32_t x0, uint32_t x1, uint32_t x2, uint32_t x3) :
    //     address(port, (x0 & 0xFF000000) | (x1 & 0x00FF0000) | (x2 & 0x0000FF00) | (x3 & 0x000000FF)) {}

    address(const address& x) {
      value.sin_family = x.value.sin_family;
      value.sin_addr.s_addr = x.value.sin_addr.s_addr;
      value.sin_port = x.value.sin_port; 
    }

    address& operator=(const address& x) {
      value.sin_family = x.value.sin_family;
      value.sin_addr.s_addr = x.value.sin_addr.s_addr;
      value.sin_port = x.value.sin_port; 
      return *this;
    }

    friend
    inline
    bool operator==(const address& x, const address& y) {
      return x.value.sin_addr.s_addr == y.value.sin_addr.s_addr && x.value.sin_port == y.value.sin_port;
    }

    friend
    inline
    bool operator!=(const address& x, const address& y) {
      return !(x == y);
    }
  }; // class address
}; // struct ipv4

struct tcp {
  static constexpr int value = SOCK_STREAM;
}; // struct tcp

struct udp {
  static constexpr int value = SOCK_DGRAM;
}; // struct udp


template<typename Domain, typename Type, int type_mask=SOCK_NONBLOCK>
class socket {
public:
  typedef int value_type;
  typedef typename Domain::address address_type;

private:
  value_type file_descriptor;
  address_type address;

public:
  socket() : file_descriptor(::socket(Domain::value, Type::value | type_mask, 0)) {
      reuse();
  }

  socket(const address_type& x) : socket()  {
    address = x;
  }

  socket(const socket& x) : file_descriptor(::socket(Domain::value, Type::value | type_mask, 0)), address(x.address) {}

  socket(socket&& x) : file_descriptor(x.file_descriptor) {
    x.file_descriptor = -1;
  }

  socket& operator=(const socket& x) {
    file_descriptor =::socket(Domain::value, Type::value | type_mask, 0);
    address = x.address;
    return *this;
  }

  socket& operator=(socket&& x) {
    file_descriptor = x.file_descriptor;
    x.file_descriptor = -1;
    return *this;
  }

  friend
  inline
  bool operator==(const socket& x, const socket& y) {
    return x.address == y.address;
  }

  friend
  inline
  bool operator!=(const socket& x, const socket& y) {
    return !(x == y);
  }

  ~socket() {
    if (file_descriptor > 0) {
      close(file_descriptor);
    }
  }

  int raw() const {
    return file_descriptor;
  }

  struct sockaddr* sockaddr() {
    return (struct sockaddr*)&(address.value);
  }

  const struct sockaddr* sockaddr() const {
    return (const struct sockaddr*)&(address.value);
  }

  void bind() {
    if (::bind(file_descriptor, sockaddr(), sizeof(address)) == -1) {
      throw std::runtime_error("bind error " + std::to_string(errno));
    }
  }

  void listen(int timeout) {
    if (::listen(file_descriptor, timeout) == -1) {
      throw std::runtime_error("listen " + std::to_string(errno));
    }
  }

  std::pair<int, socklen_t> accept(int fd) {
    std::pair<int, socklen_t> result;
    result.second = sizeof(address);
    result.first = ::accept(fd, (struct sockaddr*) &address.value, &result.second);
    return result;
  }

  size_t sendto(int sockfd, const uint8_t* buffer, size_t len, int flags=0) {
    return sendto(sockfd, buffer, len, flags, reinterpret_cast<const struct sockaddr*>(&address), sizeof(address));
  }

  size_t sendto(int sockfd, const void* buffer, size_t len, int flags=0) {
    return sendto(sockfd, buffer, len, flags, reinterpret_cast<const struct sockaddr*>(&address), sizeof(address));
  }

  void reuse() {
    int one = 1;
    setsockopt(file_descriptor, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
    one = 1;
    setsockopt(file_descriptor, SOL_SOCKET, SO_REUSEPORT, &one, sizeof(one));
  }

}; // class socket

template<typename Domain, typename Type, int type_mask=O_NONBLOCK>
struct server_socket {
  typedef scl::socket<Domain, Type, type_mask> socket_type;
  typedef typename socket_type::address_type address_type;

  socket_type socket;

  server_socket() {}

  server_socket(const address_type& address, int timeout) : socket(address) {
    socket.bind();
    socket.listen(timeout);
  }

  server_socket(const server_socket&) = default;

  server_socket& operator=(const server_socket& x) {
    socket = x.socket;
  }

  friend
  inline
  bool operator==(const server_socket& x, const server_socket& y) {
    return x.socket == y.socket;
  }

  friend
  inline
  bool operator!=(const server_socket& x, const server_socket& y) {
    return !(x == y);
  }

  int raw() const {
    return socket.raw();
  }

  std::pair<int, socklen_t> accept(int fd) {
    return socket.accept(fd);
  }

  size_t sendto(int sockfd, const uint8_t* buffer, size_t len, int flags=0) {
    return socket.sendto(sockfd, buffer, len, flags);
  }

  size_t sendto(int sockfd, const void* buffer, size_t len, int flags=0) {
    return socket.sendto(sockfd, buffer, len, flags);
  }
}; // class server_socket
} // namespace scl
