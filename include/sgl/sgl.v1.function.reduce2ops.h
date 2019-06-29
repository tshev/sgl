#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T0, typename T1, typename BinaryTransformation0, typename BinaryTransformation1>
std::pair<T0, T1> reduce2ops(ForwardIterator first, ForwardIterator last, T0 x_0, T1 y_0, BinaryTransformation0 function_0, BinaryTransformation1 function_1) {
  while (first != last) {
    x_0 = function_0(x_0, *first);
    y_0 = function_1(y_0, x_0);
    ++first;
  }
  return {std::move(x_0), std::move(y_0)};
}


template<typename ForwardIterator, typename T0, typename T1, typename BinaryTransformation0, typename BinaryTransformation1, typename Projection>
std::pair<T0, T1> reduce2ops(ForwardIterator first, ForwardIterator last, T0 x_0, T1 y_0, BinaryTransformation0 function_0, BinaryTransformation1 function_1, Projection projection) {
  while (first != last) {
    x_0 = function_0(x_0, projection(*first));
    y_0 = function_1(y_0, x_0);
    ++first;
  }
  return {std::move(x_0), std::move(y_0)};
}

} // namespace v1
} // namespace sgl
