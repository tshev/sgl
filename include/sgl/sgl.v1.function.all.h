#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename Predicate>
inline
bool all(ForwardIterator0 first0, ForwardIterator0 last0, Predicate predicate) {
  while (first0 != last0) {
    if (!predicate(*first0)) {
      return false;
    }
    ++first0;
  }
  return true;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
inline
bool all(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, Predicate predicate) {
  while (first0 != last0) {
    if (!predicate(*first0, *first1)) {
      return false;
    }
    ++first0;
    ++first1;
  }
  return true;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
inline
bool all(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator0 first2, Predicate predicate) {
  while (first0 != last0) {
    if (!predicate(*first0, *first1, *first2)) {
      return false;
    }
    ++first0;
    ++first1;
    ++first2;
  }
  return true;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename Predicate>
inline
bool all(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, Predicate predicate) {
  while (first0 != last0 && first1 != last1) {
    if (!predicate(*first0, *first1)) {
      return false;
    }
    ++first0;
    ++first1;
  }
  return true;
}
} // namespace v1
} // namespace sgl
