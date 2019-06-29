#pragma once

namespace sgl {
namespace v1 {

template<typename N>
inline
bool count_down(N& n) {
    // Precondition: $n \geq 0$
    constexpr N z(0);
    if (n == z) return false;
    n = predecessor(n);
    return true;
}


} // namespace v1
} // namespace sgl
