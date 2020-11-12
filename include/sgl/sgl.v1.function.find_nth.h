#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename T, typename N>
inline
It find_nth(It first, It last, const T& value, N n) {
    N i = 0;
    while (first != last) {
        if (*first == value) {
            ++i;
        }
        if (i == n) {
            return first;
        }
        ++first;
    }
    return first;
}

} // namespace v1
} // namespace sgl
