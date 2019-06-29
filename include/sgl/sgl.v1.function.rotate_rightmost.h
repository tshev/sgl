#pragma once

namespace sgl {
namespace v1 {
template<typename BidirectionalIterator>
inline
BidirectionalIterator rotate_rightmost(BidirectionalIterator first, BidirectionalIterator last) {
  // FIXME
  if (first == last) return first;
  auto last_fast = last;
  --last_fast;
  if (first == last_fast) return last;
  --last_fast;
  --last;
  if (first == last_fast) { std::swap(*first, *last); return first; }
  auto val = std::move(*last);
  while (first != last_fast) {
    *last = *last_fast;
    --last_fast;
    --last;
  }
  *last = *last_fast;
  *first = std::move(val);
  return last;
}
} // namespace v1
} // namespace sgl
