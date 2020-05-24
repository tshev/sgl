#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename T, typename Op1, typename Op2>
T accumulate_adjacent(ForwardIterator0 first, ForwardIterator0 last, T value, Op1 combine, Op2 reduce) {
  typedef SGLValueType(ForwardIterator0) value_type;
  typedef SGLValueType(ForwardIterator_2) value_type_2;
  static_assert(std::is_same<value_type, value_type_2>::value, "Types should be the same");

  if (first == last) { return value; }
  auto fast = first;
  ++fast;

  while (fast != last) {
    value = reduce(value, combine(*first, *fast));
    ++first;
    ++fast;
  }
  return value;
}

} // namespace v1
} // namespace sgl
