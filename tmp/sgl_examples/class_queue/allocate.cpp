#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <cstring>

void copy_bytes(uint8_t* first, uint8_t* last, uint8_t* out) {
  size_t n = last - first;
  size_t n0 = n / 8ul;

  uint64_t* first0 = reinterpret_cast<uint64_t*>(first);
  uint64_t* last0 = first0 + n0;
  uint64_t* out0 = reinterpret_cast<uint64_t*>(out);

  while (first0 != last0) {
    *out0 = *first0;
    ++out0;
    ++first0;
  }

  out = reinterpret_cast<uint8_t*>(out0);
  first = reinterpret_cast<uint8_t*>(first0);

  while (first != last) {
    *out = *first;
    ++out;
    ++first;
  }
}

void copy_byte_by_byte(uint8_t* first, uint8_t* last, uint8_t* out) {
  while (first != last) {
    *out = *first;
    ++out;
    ++first;
  }
}

int main() {
  std::allocator<std::string> allocator;
  const size_t n = 1;
  std::string* data = allocator.allocate(n);
  allocator.construct(&data[0], "123456781111111111");
  std::string* data_new = allocator.allocate(n);
  //allocator.construct(data_new, "Not Oaaaaaaaaaaaaaaaaaaaak");

  copy_byte_by_byte(reinterpret_cast<uint8_t*>(data), reinterpret_cast<uint8_t*>(data + 1), reinterpret_cast<uint8_t*>(data_new));
  ///memcpy(data_new, data, sizeof(std::string) * n);

  allocator.deallocate(data, n);
  //allocator.destroy(std::addressof(*data));
  allocator.destroy(data_new);
  allocator.deallocate(data_new, n);
}
