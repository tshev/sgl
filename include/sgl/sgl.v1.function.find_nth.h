#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename N>
inline
It find_nth(It first, It last, const SGLValueType(It)& value, N n) {
    while (first != last && (*first != value || --n != 0)) {
        ++first;
    }
    return first;
}

} // namespace v1
} // namespace sgl
