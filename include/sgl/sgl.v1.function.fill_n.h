#pragma once

namespace sgl {
namespace v1 {

template<typename It>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
It fill_n(It first, size_t n, const SGLValueType(It)& value) {
    if constexpr (std::is_base_of<std::random_access_iterator_tag, It>::value) {
        for (It last = first + n; first != last; ++first) {
            *first = value;
        }
        return first;
    } else {
        while (n != 0) { --n; *first = value; ++first; }
        return first;
    }
}

} // namespace v1
} // namespace sgl
