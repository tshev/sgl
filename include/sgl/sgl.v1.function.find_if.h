#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator find_if(ForwardIterator first, ForwardIterator last, UnaryPredicate unary_predicate) {
  while (first != last) {
    if (unary_predicate(*first)) {
      return first;
    }
    sgl::v1::successor_inplace(first);
  }
  return first;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
std::pair<ForwardIterator0, ForwardIterator1> find_if(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, BinaryPredicate binary_predicate) {
  while (first0 != last0) {
    if (binary_predicate(*first0, *first1)) {
      return std::pair<ForwardIterator0, ForwardIterator1>(first0, first1);
    }
    sgl::v1::successor_inplace(first0);
    sgl::v1::successor_inplace(first1);
  }
  return std::pair<ForwardIterator0, ForwardIterator1>(first0, first1);
}
} // namespace v1
} // namespace sgl
