#pragma once
namespace sgl {
namespace v1 {


template<typename ForwardIterator>
constexpr
void iota(ForwardIterator f, ForwardIterator l, ValueType(ForwardIterator) val) {
  while (f != l) {
    *f = val;
    ++f;
    ++val;
  }
}


template<typename ForwardIterator>
void iota(ForwardIterator f, ForwardIterator l, ValueType(ForwardIterator) val, const ValueType(ForwardIterator) &step) {
  while (f != l) {
    *f = val;
    val += step;
    ++f;
  }
}

template<typename ForwardIterator, typename Operation>
void iota(ForwardIterator f, ForwardIterator l, ValueType(ForwardIterator) val, const ValueType(ForwardIterator) &step, Operation op) {
  while (f != l) {
    *f = val;
    val = op(val, step);
    ++f;
  }
}

} // namespace v1
} // namespace sgl
