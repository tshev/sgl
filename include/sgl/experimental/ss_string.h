// Not done
#include <cstring>
#include <algorithm>

template<typename T>
struct ss_string {
  union {
   struct small_string_t {
      char data[8];
      size_t size;
      size_t capacity;
   } small_string;

   struct big_string_t {
      char* data;
      size_t size;
      size_t capacity;
   } big_string;

  } data;
  bool malloc = false;

  ss_string() {
    data.small_string.data[0] = '\0';
    data.small_string.size = 0;
  }

  ss_string(const char* str) : ss_string(str, std::strlen(str)) {}

  ss_string(const char* str, size_t len) {
    if (len < 8) {
      data.small_string.size = len;
      std::copy(str, str + len, data.small_string.data);
      data.small_string.data[len] = '\0';
    } else {
      malloc = true;
      data.big_string.size = len;
      data.big_string.data = (T*)std::malloc(len);
      std::copy(str, str + len, data.big_string.data);
      data.big_string.data[len] = '\0';
    }
  }

  ~ss_string() {
    if (malloc) {
      std::free(data.big_string.data);
    }
  }
};
