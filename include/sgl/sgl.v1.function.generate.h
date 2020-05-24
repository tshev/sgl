#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator, typename Function>
// requires(Operation(Function) && UnaryFunction(Function))
inline
void generate(ForwardIterator first, ForwardIterator last, SGLValueType(ForwardIterator) value, Function f) {
  if (first == last) { return; }
  *first = value;
  ForwardIterator slow = first;
  ++first;
  while (first != last) {
    *first = f(*slow);
    ++first;
    ++slow;
  } 
}

template<typename ForwardIterator, typename Function>
// requires(Arity(Function) is 0 && Codomain(Function) is SGLValueType(ForwardIterator))
inline
void generate(ForwardIterator first, ForwardIterator last, Function f) {
  while (first != last) {
    *first = f();
    ++first;
  } 
}


} // namespace v1
} // namespace sgl
