#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename AssociativeOperation>
inline
SGLValueType(ForwardIterator) binary_counter_reduce(ForwardIterator first, ForwardIterator last, SGLValueType(ForwardIterator) zero, AssociativeOperation op) {
  while (first != last && *first == zero) { ++first; }
 
  SGLValueType(ForwardIterator) result = *first;

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

