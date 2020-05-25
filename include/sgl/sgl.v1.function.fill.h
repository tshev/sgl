#pragma once

namespace sgl {
namespace v1 {

template<typename It>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
void fill(It first, It last, const SGLValueType(It)& value) {
    while (first != last) {
        *first = value;
        ++first;
    }
    return first;
}

} // namespace v1
} // namespace sgl
