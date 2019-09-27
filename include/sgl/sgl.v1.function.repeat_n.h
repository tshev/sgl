#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename N, typename OutputIterator>
OutputIterator repeat_n(const T& value, N n, OutputIterator out) {
    while (n-- > 0) {
        *out = value;
        ++out;
    }
    return out;
}

}  // namespace v1
}  // namespace sgl
