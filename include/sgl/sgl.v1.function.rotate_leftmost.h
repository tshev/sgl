#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator>
inline
ForwardIterator rotate_leftmost(ForwardIterator first, ForwardIterator last) {
  if (first == last) return first;

  auto fast = first;
  ++fast;
  if (fast == last) return first;

  auto val = std::move(*first);
  *first = std::move(*fast);
  ++first;
  ++fast;

  while (fast != last) {
    *first = std::move(*fast);
    ++first;
    ++fast;
  }

  *first = std::move(val);
  return first;
}

} // namespace v1
} // namespace sgl
