#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator, typename UnaryPredicate>
inline
void find_if_position_inplace(ForwardIterator& first, ForwardIterator last, UnaryPredicate unary_predicate) {
  while (first != last) {
    if (unary_predicate(first)) {
      return;
    }
    sgl::v1::successor_inplace(first);
  }
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
void find_if_position_inplace(ForwardIterator0& first0, ForwardIterator0 last0, ForwardIterator1& first1, BinaryPredicate binary_predicate) {
  while (first0 != last0) {
    if (binary_predicate(first0, first1)) {
      return;
    }
    sgl::v1::successor_inplace(first0);
    sgl::v1::successor_inplace(first1);
  }
}

} // namespace v1
} // namespace sgl
