#include <iostream>
#include <mutex>
#include <thread>
#include <csignal>
#include <sgl/sgl.h>
#include <vector>
namespace sgl { extern uint8_t* global_persistent_base_ptr; extern sgl::mmap<uint8_t> global_persistent_mmap;

/*
 * struct pp - persistent pointer
*/
template<typename T>
struct pp {
  typedef T value_type;;
  typedef uint64_t pointer_diff;

  pointer_diff offset;

  pp() = default;
  pp(pointer_diff offset) : offset(offset) {}
  pp(const pp& x) : offset(x.offset) {}

  pp& operator=(const pp& x) {
    offset = x.offset;
  }

  friend
  inline
  bool operator==(const pp& x, const pp& y) {
    return x.addressof() == y.addressof();
  }

  friend
  inline
  bool operator!=(const pp& x, const pp& y) {
    return !(x == y);
  }

  friend
  inline
  bool operator<(const pp& x, const pp& y) {
    return x.addressof() < y.addressof();
  }

  friend
  inline
  bool operator<=(const pp& x, const pp& y) {
    return !(y < x);
  }

  friend
  inline
  bool operator>(const pp& x, const pp& y) {
    return y < x;
  }

  friend
  inline
  bool operator>=(const pp& x, const pp& y) {
    return !(x < y);
  }

  T& operator*() {
    return *reinterpret_cast<T*>(addressof());
  }

  const T& operator*() const {
    return *reinterpret_cast<T*>(addressof());
  }

  pp& operator++() {
    offset += sizeof(T);
    return *this;
  }

  pp operator++(int) {
    pp x = *this;
    offset += sizeof(T);
    return x;
  }

  friend
  inline
  pp operator+(const pp& x, uint64_t n) {
    return pp(x.offset + n);
  }

  uint8_t* addressof() {
    return global_persistent_base_ptr + offset;
  }
};

struct storage {
  /*
   *
   * | capacity (8 bypes) | successor (8 bytes) | data (n bytes)"
   * | metadata (16 bytes) | data (n bytes)|
   * capacity = sizeof(metadata) + sizeof(data)
   */
  uint8_t* data_;

  storage(void* data) : data_(reinterpret_cast<uint8_t*>(data)) {}
  storage(uint8_t* data) : data_(data) {}

  uint64_t& capacity() {
    return *reinterpret_cast<uint64_t*>(data_);
  }

  const uint64_t& capacity() const {
    return *reinterpret_cast<const uint64_t*>(data_);
  }

  uint64_t& successor() {
    return *(reinterpret_cast<uint64_t*>(data_) + 1);
  }

  const uint64_t& successor() const {
    return *(reinterpret_cast<const uint64_t*>(data_) + 1);
  }

  uint8_t* data() {
    return data_ + metadata_size();
  }

  const uint8_t* data() const {
    return data_ + metadata_size();
  }

  uint64_t metadata_size() const {
    return 8 + 8;
  }

  uint64_t data_capacity() const {
    // assert(capacity() > metadata_size())
    return capacity() - metadata_size();
  }
};

template<typename T>
int mlock(pp<T> x, uint64_t v) {
  return ::mlock(static_cast<void*>(x.addressof()), v);
}

template<typename T>
int munlock(pp<T> x, uint64_t v) {
  return ::mlock(static_cast<void*>(x.addressof()), v);
}
} // namespace sgl


sgl::mmap<uint8_t> sgl::global_persistent_mmap = sgl::fmmap("/tmp/buffer-0", 1000);
uint8_t* sgl::global_persistent_base_ptr = reinterpret_cast<uint8_t*>(global_persistent_mmap.addr());

int main() {
  sgl::pp<uint8_t> data(0);
  auto mutex_ptr = sgl::construct<std::mutex>(data.addressof());
  fork();
  auto cb = [&]() { std::lock_guard<std::mutex> lock(*mutex_ptr); std::cout << "----\n"; for (int i = 0; i < 200; ++i) { std::cout << getpid() << std::endl; }};
  cb();
}
