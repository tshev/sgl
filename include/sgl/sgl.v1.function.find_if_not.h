#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename UnaryPredicate>
inline
ForwardIterator find_if_not(ForwardIterator first, ForwardIterator last, UnaryPredicate unary_predicate) {
  while (first != last && unary_predicate(*first)) {
    ++first;
  }
  return first;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_if_not(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, BinaryPredicate binary_predicate) {
  while (first0 != last0 && binary_predicate(*first0, *first1)) {
    ++first0;
    ++first1;
  }
  return std::pair<ForwardIterator0, ForwardIterator1>(first0, first1);
}

} // namespace v1
} // namespace sgl
