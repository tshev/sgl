#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename Predicate>
bool any(ForwardIterator0 first_0, ForwardIterator0 last_0, Predicate predicate) {
  while (first_0 != last_0) {
    if (predicate(*first_0)) {
      return true;
    }
    ++first_0;
  }
  return false;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
bool any(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, Predicate predicate) {
  while (first_0 != last_0) {
    if (predicate(*first_0, *first_1)) {
      return true;
    }
    ++first_0;
    ++first_1;
  }
  return false;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
bool any(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, ForwardIterator1 last_1, Predicate predicate) {
  while (first_0 != last_0 && first_1 != last_1) {
    if (predicate(*first_0, *first_1)) {
      return true;
    }
    ++first_0;
    ++first_1;
  }
  return false;
}
} // namespace v1
} // namespace sgl
