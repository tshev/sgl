#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
requires(
    sgl::v1::input_iterator(It0) && sgl::v1::readable(It0) && sgl::v1::writable(It0) &&
    sgl::v1::forward_iterator(It1) && sgl::v1::writable(It1)
)
inline
It0 move_range_value_range(It0 first, It0 middle, It0 last, SGLValueType(It1)&& value, It1 output) {
    output = std::move(first, middle, output);
    *output = std::move(value);
    ++output;
    return std::move(middle, last, output);
}


template<typename It0, typename It1>
requires(
    sgl::v1::input_iterator(It0) && sgl::v1::readable(It0) && sgl::v1::writable(It0) &&
    sgl::v1::forward_iterator(It1) && sgl::v1::writable(It1)
)
inline
It0 move_range_value_range(It0 first, It0 middle, It0 last, const SGLValueType(It1)& value, It1 output) {
    output = std::move(first, middle, output);
    *output = value;
    ++output;
    return std::move(middle, last, output);
}

template<typename It0, typename It1>
requires(
    sgl::v1::input_iterator(It0) && sgl::v1::readable(It0) && sgl::v1::writable(It0) &&
    sgl::v1::forward_iterator(It1) && sgl::v1::writable(It1)
)
inline
It0 move_range_value_range(It0 first, It0 middle, It0 last, const SGLValueType(It1)& value, It1 output, size_t n) {
    output = std::move(first, middle, output);
    *output = value;
    ++output;
    return std::move(middle, last, output);
}



}  // namespace v1
}  // namespace sgl
