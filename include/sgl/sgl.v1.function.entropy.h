#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
inline
/**
  @brief - computes the gini index
  @code
  #include <iostream>
  #include <sgl/sgl.h>
  int main() {
    std::vector<double> x = { 0.4, 0.3, 0.1, 0.4, 0.3, 0.32, 0.12 };
    double result = sgl::entropy(std::begin(x), std::end(x), 0.0);
    std::cout << result << std::endl;
  }
  @endcode
*/
T entropy(ForwardIterator f, ForwardIterator l, T val) {
    return sgl::v1::accumulate(f, l, val, [](T x, SGLValueType(ForwardIterator) y) { return x + y * sgl::v1::log2(y); });
}


template<typename ForwardIterator, typename T, typename Projection>
inline
SGLValueType(ForwardIterator) entropy(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) val, Projection projection) {
  // , typename _ = std::is_same<typename std::argument_type<Projection>::type, T>::value
  return sgl::v1::accumulate(f, l, [projection](T x, const auto& y) mutable {
      const T py = projection(y);
      return x + py * log2(py);
  });
}
} // namespace v1
} // namespace sgl
