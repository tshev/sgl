#include <cstdint>
#include <cstdlib>
#include <iostream>
namespace sgl {
namespace v1 {
struct memory_layout {
  typedef std::pair<uint64_t, uint64_t> range_type;
  void* data;

  memory_layout() {}
  memory_layout(void* data) : data(data) {}

  memory_layout(void* data, uint64_t capacity_, uint64_t head_capacity_) : data(data) {
    capacity() = capacity_;
    size() = capacity_ - 64ul - head_capacity_;
    head_capacity() = head_capacity_;
    head_size() = head_capacity_;

  }

  uint64_t& capacity() {
    return *static_cast<uint64_t*>(data);
  }

  const uint64_t& capacity() const {
    return *static_cast<const uint64_t*>(data);
  }

  uint64_t& size() {
    return *(static_cast<uint64_t*>(data) + 1);
  }

  const uint64_t& size() const {
    return *(static_cast<const uint64_t*>(data) + 1);
  }

  uint64_t& head_capacity() {
    return *(static_cast<uint64_t*>(data) + 2);
  }

  const uint64_t& head_capacity() const {
    return *(static_cast<const uint64_t*>(data) + 2);
  }

  uint64_t& head_size() {
    return *(static_cast<uint64_t*>(data) + 3);
  }

  const uint64_t& head_size() const {
    return *(static_cast<const uint64_t*>(data) + 3);
  }

  range_type* head_ranges() {
    return (range_type*)(static_cast<uint64_t*>(data) + 4);
  }

  const range_type* head_ranges() const {
    return (const range_type*)(static_cast<uint64_t*>(data) + 4);
  }

  void* data_segemnt() {
    64 + 64 + head_capacity();
  }
};
} // namespace v1
} // namespace sgl
void* falloc(size_t n) {
  const char* layout = "layout.txt";

  //static std::vector<std::string> folders;
  //constexpr size_t initial_size = 24;
  //static std::vector<uint8_t*> mmaped;
  //(n * sysconf(_SC_PAGE_SIZE))

}

/*

int main() {
  uint64_t file_capacity = 1000;
  uint64_t initial_allocator_length = 128;
  void* data = malloc(1024 * 1024);
  sgl::memory_layout memory_layout(data, file_capacity, initial_allocator_length);

}
*/
