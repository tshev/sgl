#pragma once

namespace sgl {
namespace v1 {

template<typename It>
inline
void delta_encode(It first, It last) {
    if (first == last) return;
    auto prev_value = *first;
    ++first;
    while (first != last) {
        auto delta = *first - prev_value;
        prev_value = *first;
        *first = delta;
        ++first;
    }
}

} // namespace sgl
} // namespace v1
