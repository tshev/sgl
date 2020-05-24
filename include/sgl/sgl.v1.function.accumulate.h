#pragma once
namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename T>
T accumulate(ForwardIterator first, ForwardIterator last, T val) {
    while (first != last) {
        val += *first;
        ++first;
    }
    return val;
}

template<typename ForwardIterator, typename T, typename BinaryOperation>
inline
T accumulate(ForwardIterator first, ForwardIterator last, T val, BinaryOperation binary_operation) {
    while (first != last) {
        val = binary_operation(val, *first);
        ++first;
    }
    return val;
}

template<typename ForwardIterator_1, typename ForwardIterator_2, typename T, typename Op1, typename Op2>
SGLValueType(ForwardIterator_1) accumulate(ForwardIterator_1 f1, ForwardIterator_1 l1, ForwardIterator_2 f2, T value, Op1 op1, Op2 op2) {
  typedef SGLValueType(ForwardIterator_1) value_type;
  typedef SGLValueType(ForwardIterator_2) value_type_2;
  static_assert(std::is_same<value_type, value_type_2>::value, "Types should be the same");

  while (f1 != l1) {
    value = op2(value, op1(*f1, *f2));
    ++f1;
    ++f2;
  }
  return value;
}

template<typename ForwardIterator_1, typename ForwardIterator_2, typename ForwardIterator_3, typename T, typename Op1, typename Op2>
SGLValueType(ForwardIterator_1) accumulate(ForwardIterator_1 f1, ForwardIterator_1 l1, ForwardIterator_2 f2, ForwardIterator_3 f3, SGLValueType(ForwardIterator_1) value, Op1 op1, Op2 op2) {
  typedef SGLValueType(ForwardIterator_1) value_type;
  typedef SGLValueType(ForwardIterator_2) value_type_2;
  static_assert(std::is_same<value_type, value_type_2>::value, "Types should be the same");

  while (f1 != l1) {
    value = op2(value, op1(*f1, *f2, *f3));
    ++f1;
    ++f2;
    ++f3;
  }
  return value;
}

template<typename ForwardIterator_1, typename ForwardIterator_2, typename ForwardIterator_3, typename ForwardIterator_4, typename T, typename Op1, typename Op2>
SGLValueType(ForwardIterator_1) accumulate(ForwardIterator_1 f1, ForwardIterator_1 l1, ForwardIterator_2 f2, ForwardIterator_3 f3, ForwardIterator_4 f4, SGLValueType(ForwardIterator_1) value, Op1 op1, Op2 op2) {
  typedef SGLValueType(ForwardIterator_1) value_type;
  typedef SGLValueType(ForwardIterator_2) value_type_2;
  static_assert(std::is_same<value_type, value_type_2>::value, "Types should be the same");

  while (f1 != l1) {
    value = op2(value, op1(*f1, *f2, *f3, *f4));
    ++f1;
    ++f2;
    ++f3;
    ++f4;
  }
  return value;
}
} // namespace v1
} // namespace sgl
