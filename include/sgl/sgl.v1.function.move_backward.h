#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
/*
requires(
    sgl::v1::input_iterator(It0) && sgl::v1::readable(It0) && sgl::v1::writable(It0) &&
    sgl::v1::bidirectional_iterator(It1) && sgl::v1::writable(It1)
)
*/
inline
It1 move_backward(It0 first, It0 last, It1 out) {
    while (first != last) {
        --out;
        --last;
        *out = std::move(*last);
    }
    return out;
}

} // namespace v1
} // namespace sgl
