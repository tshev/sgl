#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator1, typename ForwardIterator2, typename T>
inline
SGLValueType(ForwardIterator1) accumulate_squared_diffs(ForwardIterator1 f1, ForwardIterator1 l1, ForwardIterator2 f2, const T& identity_element) {
  typedef T value_type;
  return accumulate(f1, l1, f2, identity_element, sgl::v1::delta_square<value_type>{}, std::plus<value_type>{});
}

} // namespace v1
} // namespace sgl
