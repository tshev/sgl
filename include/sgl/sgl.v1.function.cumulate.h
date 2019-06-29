#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator, typename T, typename Op, typename OpNegate>
/**
 *  @brief function cumulate - cumulate version with generic operations
*/

// requires(
//   ForwardIterator(ForwardIterator) &&
//   OutputIterator(OutputIterator) &&
//   Regular(ValueType(ForwardIterator)) &&
//   AbelianSemigroup(ValueType(ForwardIterator), Op, OpNegate)
// )
OutputIterator cumulate(ForwardIterator f, ForwardIterator m, ForwardIterator l, OutputIterator out, T identity_element, Op op, OpNegate op_negate) {
  ForwardIterator it = f;
  while (it != m) {
    identity_element = op(identity_element, *it);
    ++it;
  }
  *out = identity_element;
  ++out;

  while (it != l) {
    identity_element = op_negate(identity_element, *f);
    identity_element = op(identity_element, *it);
    *out = identity_element;

    ++it;
    ++f;
    ++out;
  }
  return out;
}

template<typename ForwardIterator, typename OutputIterator, typename T>
/**
 * @brief function cumulate - computes a prefix scan of the elements of the collection with window.
 *
 * @code
 * #include <sgl/algorithm>
 * #include <iostream>
 *
 * int main() {
 *   int data[] = { 1, 2, 3, 4, 5, 6 };
 *   size_t length = sizeof(data) / sizeof(*data)
 *   size_t offset = 2;
 *   int partial_sums[sgl::cumulate_size(length, offset)];
 *   sgl::cumulate(data, data + offset, data + length); // 3 5 7 9 11
 *   
 *   for (auto x : data) {
 *     std::cout << x << " ";
 *   }
 *   std::cout << "\n";
 * }
 * @endcode
*/

// requires(
//   ForwardForwardIteratorerator(ForwardIterator) &&
//   OutputIterator(OutputIterator) &&
//   Regular(ValueType(ForwardIterator)) &&
//   AbelianSemigroup(
//     ValueType(ForwardIterator),
//     ValueType(ForwardIterator)::operator+=(const ValueType(ForwardIterator)&),
//     ValueType(ForwardIterator)::operator-=(const ValueType(ForwardIterator)&)
//   )
// )
OutputIterator cumulate(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator out, T identity_element) {
  ForwardIterator it = first;
  while (it != middle) {
    identity_element += *it;
    ++it;
  }
  *out = identity_element;
  ++out;

  while (it != last) {
    identity_element -= *first;
    identity_element += *it;
    *out = identity_element;

    ++it;
    ++first;
    ++out;
  }
  return out;
}


template<typename T>
constexpr
inline
T cumulate_size(T length, T window) {
  return std::max(length - window + T{1}, T{0});
}

namespace transformation {
template <typename ForwardIterator, typename OutputIterator, typename T>
OutputIterator cumulate(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator out, T current_value) {
  ForwardIterator it = first;
  while (it != middle) {
    current_value += *it;
    ++it;
  }
  *out = current_value;
  ++out;

  while (it != last) {
    current_value -= *first;
    current_value += *it;
    *out = current_value;

    ++it;
    ++first;
    ++out;
  }
  return out;
}

template<typename ForwardIterator, typename T, typename OutputIterator, typename Operation1, typename Operation2, typename Projection>
OutputIterator cumulate(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                        OutputIterator out,  T current_value, Operation1 operation, Operation2 operation_inv, Projection projection) {
  ForwardIterator it = first;
  while (it != middle) {
    current_value = operation(current_value, projection(*it));
    ++it;
  }
  *out = current_value;
  ++out;

  while (it != last) {
    current_value = operation_inv(current_value, projection(*first));
    current_value = operation(current_value, projection(*it));
    *out = current_value;

    ++it;
    ++first;
    ++out;
  }
  return out;
} // function cumulate

template<typename ForwardIterator, typename T, typename OutputIterator, typename Operation1, typename Operation2>
OutputIterator cumulate(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                        OutputIterator out,  T current_value, Operation1 operation, Operation2 operation_inv) {
  ForwardIterator it = first;
  while (it != middle) {
    current_value = operation(current_value, *it);
    ++it;
  }
  *out = current_value;
  ++out;

  while (it != last) {
    current_value = operation_inv(current_value, *first);
    current_value = operation(current_value, *it);
    *out = current_value;

    ++it;
    ++first;
    ++out;
  }
  return out;
} // function cumulate
} // namespace transformation
} // namespace v1
} // namespace sgl
