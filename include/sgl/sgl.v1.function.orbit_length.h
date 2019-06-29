#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
size_t orbit_length(ForwardIterator first, const T& x) {
  size_t i = 0;
  while (*first != x) {
    ++first;
    ++i;
  }
  return i;
}

} // namespace v1
} // namespace sgl
