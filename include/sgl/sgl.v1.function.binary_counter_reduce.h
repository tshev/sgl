#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename AssociativeOperation>
inline
ValueType(ForwardIterator) binary_counter_reduce(ForwardIterator first, ForwardIterator last, ValueType(ForwardIterator) zero, AssociativeOperation op) {
  while (first != last && *first == zero) { ++first; }
 
  ValueType(ForwardIterator) result = *first;

  ++first; 
  while (first != last) {
    if (*first != zero) {
      result = op(result, *first);
    }
    ++first;
  }
  return result;
}

} // namespace v1
} // namespace sgl

