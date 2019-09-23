#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename OutputIterator>
OutputIterator repeat_n(const T& value, size_t n, OutputIterator out) {
    while (n-- > 0) {
        *out = value;
        ++out;
    }
    return out;
}

}  // namespace v1
}  // namespace sgl
