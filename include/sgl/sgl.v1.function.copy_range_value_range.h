#pragma once

namespace sgl {
namespace v1 {
template<typename It0, typename It1, typename T>
// requires(InputIterator(It0) && SGLValueType(It0) == T) 
inline
It1 copy_range_value_range(It0 first, It0 middle, It0 last, const T& x, It1 output) {
    output = std::copy(first, middle, output);
    *output = x;
    ++output;
    return std::copy(middle, last, output);
}

template<typename It0, typename It1, typename T>
// requires(InputIterator(It0) && SGLValueType(It0) == T) 
It1 copy_range_value_range(It0 first, It0 middle, It0 last, const T& x, size_t n, It1 output) {
    output = std::copy(first, middle, output);
    output = sgl::v1::repeat_n(x, n, output);
    return std::copy(middle, last, output);
}

} // namespace v1
} // namespace sgl
