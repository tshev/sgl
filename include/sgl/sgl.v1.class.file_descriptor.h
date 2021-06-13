#pragma once

namespace sgl {
namespace v1 {
typedef struct stat fd_stat;

struct file_descriptor_error : std::exception {
  static const constexpr std::pair<int, const char*> errors[] = {
    {EACCES, "The requested access to the file is not allowed, or search"
              "permission is denied for one of the directories in the path"
              "prefix of pathname, or the file did not exist yet and write"
              "access to the parent directory is not allowed"},
    {EDQUOT, "Where O_CREAT is specified, the file does not exist, and the"
              "user's quota of disk blocks or inodes on the filesystem has"
              "been exhausted."},
    {EEXIST, "pathname already exists and O_CREAT and O_EXCL were used."},
    {EFAULT, "pathname points outside your accessible address space."},
    {EFBIG, "EOVERFLOW"},
    {EINTR, "While blocked waiting to complete an open of a slow device"
            "(e.g., a FIFO; see fifo(7)), the call was interrupted by a"
            "signal handler; see signal(7)."},
    {EINVAL, "The filesystem does not support the O_DIRECT flag.  See NOTES"
             "for more information.\n"
             "Invalid value in flags.\n"
             "O_TMPFILE was specified in flags, but neither O_WRONLY nor O_RDWR was specified\n"
             "O_CREAT was specified in flags and the final component"
             "(\"basename\") of the new file's pathname is invalid (e.g., it"
             "contains characters not permitted by the underlying"
             "filesystem)."},
    {EISDIR, "pathname refers to a directory and the access requested"
             "involved writing (that is, O_WRONLY or O_RDWR is set).\n"
             "pathname refers to an existing directory, O_TMPFILE and one of"
             "O_WRONLY or O_RDWR were specified in flags, but this kernel"
             "version does not provide the O_TMPFILE functionality.\n"},
    {ELOOP, "Too many symbolic links were encountered in resolving pathname.\n"
            "pathname was a symbolic link, and flags specified O_NOFOLLOW but not O_PATH."},
    {EMFILE, "The per-process limit on the number of open file descriptors"
             "has been reached (see the description of RLIMIT_NOFILE in"
             "getrlimit(2))."},
    {ENAMETOOLONG, "pathname was too long."},
    {ENFILE, "The system-wide limit on the total number of open files has been reached."},
    {ENODEV, "pathname refers to a device special file and no corresponding"
             "device exists.  (This is a Linux kernel bug; in this situation"
             "ENXIO must be returned.)"},
    {ENOENT, "O_CREAT is not set and the named file does not exist.  Or, a"
              "directory component in pathname does not exist or is a"
              "dangling symbolic link.\n"
              "pathname refers to a nonexistent directory, O_TMPFILE and one"
              "of O_WRONLY or O_RDWR were specified in flags, but this kernel"
              "version does not provide the O_TMPFILE functionality."},
    {ENOMEM, "The named file is a FIFO, but memory for the FIFO buffer can't"
             "be allocated because the per-user hard limit on memory"
             "allocation for pipes has been reached and the caller is not"
             "privileged; see pipe(7).\n"
             "Insufficient kernel memory was available"},
    {ENOSPC, "pathname was to be created but the device containing pathname"
             "has no room for the new file."},
    {ENOTDIR, "A component used as a directory in pathname is not, in fact, a"
              "directory, or O_DIRECTORY was specified and pathname was not a"
              "directory."},
    {ENXIO, "O_NONBLOCK | O_WRONLY is set, the named file is a FIFO, and no"
            "process has the FIFO open for reading.\n"
			      "The file is a device special file and no corresponding device exists."},
		{EOPNOTSUPP, "The filesystem containing pathname does not support O_TMPFILE"},
		{EOVERFLOW, "pathname refers to a regular file that is too large to be"
                "opened.  The usual scenario here is that an application"
                "compiled on a 32-bit platform without -D_FILE_OFFSET_BITS=64"
                "tried to open a file whose size exceeds (1<<31)-1 bytes; see"
                "also O_LARGEFILE above.  This is the error specified by"
                "POSIX.1; in kernels before 2.6.24, Linux gave the error EFBIG"
                "for this case."},
		{EPERM, "The O_NOATIME flag was specified, but the effective user ID of"
            "the caller did not match the owner of the file and the caller"
            "was not privileged.\n"
						"The operation was prevented by a file seal; see fcntl(2)."},
		{EROFS, "pathname refers to a file on a read-only filesystem and write access was requested"},
		{ETXTBSY, "pathname refers to an executable image which is currently"
              "being executed and write access was requested."},
		{ETXTBSY, "pathname refers to a file that is currently in use as a swap"
              "file, and the O_TRUNC flag was specified."},
		{ETXTBSY, "pathname refers to a file that is currently being read by the"
              "kernel (e.g. for module/firmware loading), and write access"
              "was requested."},
		{EWOULDBLOCK, "The O_NONBLOCK flag was specified, and an incompatible lease"
                  "was held on the file (see fcntl(2))."},
		{EBADF, "dirfd is not a valid file descriptor."},
		{ENOTDIR, "pathname is a relative pathname and dirfd is a file descriptor"
              "referring to a file other than a directory."}
  };

  int error_code;
  file_descriptor_error(int x) : error_code(x) {}

  const char* what() const noexcept {
      /*
      auto first = std::begin(sgl::v1::file_descriptor_error::errors);
      auto last = std::end(file_descriptor_error::errors);
      int ec = error_code;
      auto position = std::find_if(first, last, [ec](const auto& x) {
          return x.first == ec;
      });
      if (position == last) {
            return "unknown error\n";
      }
      return position->second;
      */
      return "file_descriptor_error";
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
  // static constexpr int tmp_file = O_TMPFILE;
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

public:

  file_descriptor() = default;
  file_descriptor(const std::string& path) : file_descriptor(path.data()) {}
  file_descriptor(const char* name) : fd(open(name, io::read_only)) {
    if (fd == -1) { throw file_descriptor_error(errno); }
  }

  file_descriptor(const char* name, int flags) : fd(open(name, flags)) {
    if (fd == -1) { throw file_descriptor_error(errno); }
  }

  file_descriptor(const char* name, int flags, mode_t mode) : fd(open(name, flags, mode)) {
    if (fd == -1) { throw file_descriptor_error(errno); }
  }

  file_descriptor(const char *path_name, mode_t mode) : fd(creat(path_name, mode)) {}

  file_descriptor(const file_descriptor &) = delete;

  file_descriptor(file_descriptor &&fd) : fd(fd.fd) {
    fd.fd = -2;
  }

	void chown(uid_t owner, gid_t group) {
		int result = fchown(raw(), owner, group);
		if (result == 0) { return; }
		throw file_descriptor_error(errno);
	}

  template<typename T>
  size_t read(T& x) {
    ssize_t result = read(&x, sizeof(T));
		if (result < 0) {
			throw file_descriptor_error(errno);
		}
		return result;
  }

  size_t read(std::string& x) {
    size_t count = 0;
    size_t size = 0;
    do {
        if (x.capacity() < size + 4096) {
            x.reserve(std::max(size + 4096, x.capacity() * 2));
        }
        x.resize(size + 4096);
        count = ::read(fd, &x[size], 4096);
        size += count;
    } while (count > 0);
    x.resize(size);
    return count; 
  }

  char* copy(char* out) {
    while (true) {
        size_t count = ::read(fd, out, 4096);
        out += count;
        if (count == 0) return out;
    }
  }

  template<typename T>
  size_t write(T data, size_t n) {
    ssize_t result = ::write(fd, data, n);
		if (result < 0) {
			throw file_descriptor_error(errno);
		}
		return result;
  }

  size_t write_string(const char *str) {
    size_t n = orbit_length(str, '\0');
    ssize_t result = ::write(fd, str, n);
		if (result < 0) {
			throw file_descriptor_error(errno);
		}
		return result;
  }

  int value() const { return fd; }

  int reset() {
    int result = fd;
    fd = -3;
    return result;
  }

  fd_stat stat() const {
    sgl::v1::fd_stat fd_stat;
    fstat(fd, &fd_stat);
    return fd_stat;
  }

  int raw() const { return fd; }

  template<typename T>
  friend
  inline
  sgl::v1::file_descriptor& operator>>(sgl::v1::file_descriptor &file_descriptor, T& x) {
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


template<typename M>
void mkdir(const char* name, M mode) {
    //  mode_t 
  if (::mkdir(name, mode) != 0) {
    throw mkdir_error();
  }
}



struct constigious_iterator_tag {};
struct unconstigious_iterator_tag {};

struct urandom {
  sgl::v1::file_descriptor file_descriptor;

  urandom() : file_descriptor("/dev/urandom") {};

  template<typename ForwardIterator>
  void fill(ForwardIterator first, ForwardIterator last) {
    while (first != last) {
      *this >> *first;
      ++first;
    }
  }

  template<typename ForwardIterator>
  void fill_fast(ForwardIterator first, ForwardIterator last) {
    fill_n_fast(first, last - first); 
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
  sgl::v1::urandom& operator>>(sgl::v1::urandom& urandom, T& x) {
    urandom.file_descriptor.read(x);
    return urandom;
  }
}; // struct urandom
} // namespace v1
} // namespace sgl
