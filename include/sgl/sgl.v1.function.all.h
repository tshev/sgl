#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename Predicate>
bool all(ForwardIterator0 first_0, ForwardIterator0 last_0, Predicate predicate) {
  while (first_0 != last_0) {
    if (!predicate(*first_0)) {
      return false;
    }
    ++first_0;
  }
  return true;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
bool all(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, Predicate predicate) {
  while (first_0 != last_0) {
    if (!predicate(*first_0, *first_1)) {
      return false;
    }
    ++first_0;
    ++first_1;
  }
  return true;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
bool all(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, ForwardIterator0 first_2, Predicate predicate) {
  while (first_0 != last_0) {
    if (!predicate(*first_0, *first_1, *first_2)) {
      return false;
    }
    ++first_0;
    ++first_1;
    ++first_2;
  }
  return true;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
bool all(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, ForwardIterator1 last_1, Predicate predicate) {
  while (first_0 != last_0 && first_1 != last_1) {
    if (!predicate(*first_0, *first_1)) {
      return false;
    }
    ++first_0;
    ++first_1;
  }
  return true;
}
} // namespace v1
} // namespace sgl
