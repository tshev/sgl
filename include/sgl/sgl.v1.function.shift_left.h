#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
ForwardIterator shift_left(ForwardIterator first, ForwardIterator middle, ForwardIterator last) {
  // could be optimized with partial memcpy
  auto slow = first;
  auto fast = middle;
  while (fast != last) {
    *slow = std::move(*fast);
    ++slow;
    ++fast;
  }
  return slow;
}


template<typename ForwardIterator>
inline
ForwardIterator shift_left(ForwardIterator first, ForwardIterator middle, size_t n) {
  for (size_t i = 0; i != n; ++i) {
    *first = *middle;
    ++first;
    ++middle;
  }
}

} // namespace v1
} // namespace sgl
