#pragma once

namespace sgl {
namespace v1 {

template<typename It>
// requires(ForwardIterator(It))
inline
It lower_bound(It first, It last, const ValueType(It)& value) {
    while (first != last) {
      It middle = first;
      sgl::v1::advance_to_middle(middle, last);
      if (*middle < value) {
          first = middle;
          ++first;
      } else {
          last = middle;
      }
    }
    return first;
}


template<typename It, typename T, typename BinaryPredicate>
inline
It lower_bound(It first, It last, const T& value, BinaryPredicate pred) {
    while (first != last) {
      It middle = first;
      sgl::v1::advance_to_middle(middle, last);
      if (pred(*middle, value)) {
          first = middle;
          ++first;
      } else {
          last = middle;
      }
    }
    return first;
}


template<typename It, typename T, typename BinaryPredicate, typename Projection>
inline
It lower_bound(It first, It last, const T& value, BinaryPredicate pred, Projection proj) {
    while (first != last) {
      It middle = first;
      sgl::v1::advance_to_middle(middle, last);
      if (pred(proj(*middle), value)) {
          first = middle;
          ++first;
      } else {
          last = middle;
      }
    }
    return first;
}


} // namespace v1
} // namespace sgl
