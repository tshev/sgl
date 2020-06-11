#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename T, typename N>
inline
It expression_end(It first, It last, const T& open, const T& close, N n_open, N n_close) {
    // assert(valid_expression(first, last, open, close));
    while (first != last) {
        if (*first == open) {
            ++n_open;
        } else if (*first == close) {
            ++n_close;
        }
        if (n_open == n_close) {
            return first;
        }
    }
    return last;
}

template<typename It, typename T>
inline
It expression_end(It first, It last, const T& open, const T& close) {
    return sgl::v1::expression_end(first, last, open, close, size_t(0), size_t(1));
}

template<typename It, typename T>
inline
It expression_end(It first, It last, const T& open) {
    return sgl::v1::expression_end(first, last, open, open, size_t(0), size_t(1));
}

} // namespace v1
} // namespace sgl
