#pragma once
// include: #include <memory>

namespace sgl {
namespace v1 {
#ifndef move
//static_assert(false, "Connot find std::move");
#endif


template<typename BidirectionalIterator, typename T>
inline
BidirectionalIterator find_with_sentinel_ref(BidirectionalIterator first, BidirectionalIterator last, T &value) {
  if (first == last) return first;
  auto last_minus_one = last;
  --last_minus_one;
  auto sentinel = std::move(*last_minus_one);
  *last_minus_one = std::move(value);
  
  while (*first != *last_minus_one) {
    ++first;
  }

  if (first == last_minus_one) {
    if (*last_minus_one == sentinel) {
      value = std::move(*last_minus_one);
      *last_minus_one = std::move(sentinel);
      return last_minus_one;
    }  else {
      value = std::move(*last_minus_one);
      *last_minus_one = std::move(sentinel);
      return last;
    }
  } else {
    value = std::move(*last_minus_one);
    *last_minus_one = std::move(sentinel);
    return first;
  }
}


template<typename BidirectionalIterator, typename T>
inline
BidirectionalIterator find_with_sentinel(BidirectionalIterator first, BidirectionalIterator last, const T &value) {
  if (first == last) return first;
  auto last_minus_one = last;
  --last_minus_one;
  auto sentinel = std::move(*last_minus_one);
  *last_minus_one = value;
  
  while (*first != *last_minus_one) {
    ++first;
  }

  if (first == last_minus_one) {
    if (*last_minus_one == sentinel) {
      *last_minus_one = std::move(sentinel);
      return last_minus_one;
    }  else {
      *last_minus_one = std::move(sentinel);
      return last;
    }
  } else {
    *last_minus_one = std::move(sentinel);
    return first;
  }
}
} // namespace v1
} // namespace sgl
