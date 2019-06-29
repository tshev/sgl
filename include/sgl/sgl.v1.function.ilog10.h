#pragma once

namespace sgl {
namespace v1 {

template<typename T>
constexpr
inline
T ilog10(T x) {
    T r(0);
    constexpr T ten(10);
    constexpr T zero(0);
    while (true) {
        x /= ten;
        if (x == zero) { return r; }
        ++r;
    }
    return r;
}

} // namespace v1
} // namespace sgl
