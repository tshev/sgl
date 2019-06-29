#pragma once
namespace sgl {
namespace v1 {


template<typename ForwardIterator, typename N>
N unique_count(ForwardIterator first, ForwardIterator last, N n) {
  if (first == last) return n;
  ForwardIterator slow = first;
  ++n;
  ++first;
  while (first != last) {
    if (*slow != *first) {
      ++n;
      slow = first;
    }
    ++first;
  }
  return n;
}


template<typename ForwardIterator, typename N, typename Predicate>
N unique_count(ForwardIterator first, ForwardIterator last, N n, Predicate predicate) {
  if (first == last) return n;
  ForwardIterator slow = first;
  ++n;
  ++first;
  while (first != last) {
    if (!predicate(*slow, *first)) {
      ++n;
      slow = first;
    }
    ++first;
  }
  return n;
}


template<typename ForwardIterator>
size_t unique_count(ForwardIterator f, ForwardIterator l) {
  return unique_count(f, l, size_t(0));
}


} // namespace v1
} // namespace sgl
