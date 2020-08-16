#pragma once

namespace sgl {
namespace v1 {


template<typename It>
inline
void delta_decode(It first, It last) {
    if (first == last) return;
    It fast = first;
    ++fast;
    while (fast != last) {
        *fast += *first;
        ++first;
        ++fast;
    }
}

} // namespace sgl
} // namespace v1
