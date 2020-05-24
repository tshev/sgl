#pragma once
namespace sgl {
namespace v1 {


template<typename ForwardIterator>
inline
constexpr
void iota(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) val) {
  while (f != l) {
    *f = val;
    ++f;
    ++val;
  }
}


template<typename ForwardIterator>
inline
constexpr
void iota(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) val, const SGLValueType(ForwardIterator) &step) {
  while (f != l) {
    *f = val;
    val += step;
    ++f;
  }
}

template<typename ForwardIterator, typename Operation>
inline
constexpr
void iota(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) val, const SGLValueType(ForwardIterator) &step, Operation op) {
  while (f != l) {
    *f = val;
    val = op(val, step);
    ++f;
  }
}

} // namespace v1
} // namespace sgl
