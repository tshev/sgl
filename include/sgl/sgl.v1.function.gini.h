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
    double result = sgl::gini(std::begin(x), std::end(x), 0.0);
    std::cout << result << std::endl;
  }
  @endcode
*/
T gini(ForwardIterator first, ForwardIterator last, const T& val) {
    return std::accumulate(first, last, val, [](T x, SGLValueType(ForwardIterator) y) { return x + (T(1) - y) * y; });
}


template<typename ForwardIterator, typename T, typename Projection>
inline
T gini(ForwardIterator first, ForwardIterator last, const T& val, Projection projection) {
    return std::accumulate(first, last, val, [projection](T x, const auto& y) mutable {
        const T py = projection(y);
        return x + (1 - py) * py;
    });
}

} // namespace v1
} // namespace sgl
