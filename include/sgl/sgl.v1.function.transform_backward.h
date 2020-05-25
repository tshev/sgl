#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1, typename UnaryFunction>
requires(sgl::v1::input_iterator(It0) && sgl::v1::readable(It0) && sgl::v1::bidirectional_iterator(It1) && sgl::v1::writable(It1))
inline
It1 transform_backward(It0 first, It0 last, It1 out, UnaryFunction unary_function) {
    while (first != last) {
        --out;
        *out = unary_function(*first);
        ++first;
    }
    return out;
}

} // namespace v1
} // namespace sgl
