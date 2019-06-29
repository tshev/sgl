#pragma once

namespace scl {
typedef struct stat fd_stat;

struct file_descriptor_open_error : std::exception {
  const char* what() const noexcept {
    return "file_descriptor_open_error";
  }
};

struct file_descriptor_close_error : std::exception {
  const char* what() const noexcept {
    return "file_descriptor_close_error";
  }
};

struct mkdir_error: std::exception {
  const char* what() const noexcept {
    return "mkdir_error";
  }
};


struct io {
  static constexpr int read_only = O_RDONLY;
  static constexpr int write_only = O_WRONLY;
  static constexpr int read_write = O_RDWR;
  static constexpr int creat = O_CREAT;
  static constexpr int tmp_file = O_TMPFILE;
  static constexpr int append = O_APPEND;

  // permissions
  // for an owner
  static constexpr mode_t rwxo = S_IRWXU;
  static constexpr mode_t ro = S_IRUSR;
  static constexpr mode_t wo = S_IWUSR;
  static constexpr mode_t rwo = ro | wo;
  static constexpr mode_t xo = S_IXUSR;

  // for a group
  static constexpr mode_t rwxg = S_IRWXG;
  static constexpr mode_t rg = S_IRGRP;
  static constexpr mode_t wg = S_IWGRP;
  static constexpr mode_t rwg = rg | wg;
  static constexpr mode_t xg = S_IXGRP;

  // for other
  static constexpr mode_t rwxt = S_IRWXO;
  static constexpr mode_t rt = S_IROTH;
  static constexpr mode_t wt = S_IWOTH;
  static constexpr mode_t rwt = rt | wt;
  static constexpr mode_t xt = S_IXOTH;


  // outputs
  static constexpr int stdin = 0;
  static constexpr int stdout = 1;
  static constexpr int stderr = 2;

  // file kinds
  static constexpr mode_t regular_file = S_IFREG;
};

class file_descriptor {
  static constexpr size_t bogus_value = 1LL << 30LL;
  int fd = -1;
  size_t last_length_ = file_descriptor::bogus_value;

public:
  file_descriptor() = default;
  file_descriptor(const char* name) : fd(open(name, io::read_only)), last_length_(file_descriptor::bogus_value) {
    if (fd == -1) { throw file_descriptor_open_error(); }
  }

  file_descriptor(const char* name, int flags) : fd(open(name, flags)), last_length_(file_descriptor::bogus_value) {
    if (fd == -1) { throw file_descriptor_open_error(); }
  }

  file_descriptor(const char* name, int flags, mode_t mode) : fd(open(name, flags, mode)), last_length_(file_descriptor::bogus_value) {
    if (fd == -1) { throw file_descriptor_open_error(); }
  }

  file_descriptor(const char *path_name, mode_t mode) : fd(creat(path_name, mode)), last_length_(file_descriptor::bogus_value) {}

  file_descriptor(const file_descriptor &) = delete;

  file_descriptor(file_descriptor &&fd) : fd(fd.fd) {
    fd.fd = -2;
  }

  operator bool() const {
    return last_length_ == file_descriptor::bogus_value;
  }

  template<typename T>
  size_t read(T out, size_t n) {
    last_length_ = ::read(fd, out, static_cast<int>(n));
    return last_length_;
  }

  template<typename T>
  size_t read(T& x) {
    return read(&x, sizeof(T));
  }

  template<typename T>
  size_t write(T data, size_t n) {
    return ::write(fd, data, n);
  }

  size_t write_string(const char *str) {
    size_t n = orbit_length(str, '\0');
    return ::write(fd, str, n);
  }

  int value() const { return fd; }

  int reset() {
    int result = fd;
    fd = -3;
    return result;
  }

  fd_stat stat() const {
    scl::fd_stat fd_stat;
    fstat(fd, &fd_stat);
    return fd_stat;
  }

  int raw() const { return fd; }

  template<typename T>
  friend
  inline
  scl::file_descriptor& operator>>(scl::file_descriptor &file_descriptor, T& x) {
    file_descriptor.read(x);
    return file_descriptor;
  }

  void truncate(size_t n) {
    ftruncate(raw(), n);
  }

  ~file_descriptor() {
    if (2 < fd) {
      close(fd);
    }
  }
};
void mkdir(const char* name, mode_t mode) {
  if (::mkdir(name, mode) != 0) {
    throw mkdir_error();
  }
}

struct constigious_iterator_tag {};
struct unconstigious_iterator_tag {};

struct urandom {
  scl::file_descriptor file_descriptor;

  urandom() : file_descriptor("/dev/urandom") {};

  template<typename ForwardIterator>
  void fill(ForwardIterator first, ForwardIterator last) {
    while (first != last) {
      *this >> *first;
      ++first;
    }
  }

  template<typename ForwardIterator>
  void fill_falst(ForwardIterator first, ForwardIterator last) {
    fill_n(first, last - first); 
  }

  template<typename ForwardIterator>
  ForwardIterator fill_n(ForwardIterator first, size_t n) {
    for (size_t i = 0; i != n; ++i) {
      *this >> *first;
      ++first;
    }
    return first;
  }

  template<typename ForwardIterator>
  ForwardIterator fill_n_fast(ForwardIterator first, size_t n) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type T;
    file_descriptor.read(&(*first), n * sizeof(T));
    return first + n;
  }

  template<typename T>
  friend
  inline
  scl::urandom& operator>>(scl::urandom& urandom, T& x) {
    urandom.file_descriptor.read(x);
    return urandom;
  }
}; // struct urandom

} // namespace scl
