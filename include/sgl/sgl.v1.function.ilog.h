#pragma once

namespace sgl {
namespace v1 {

template<typename T>
constexpr
inline
T ilog(T x, const T& base) {
    T r(0);
    constexpr T zero(0);
    while (true) {
        x /= base;
        if (x == zero) { return r; }
        ++r;
    }
    return r;
}

} // namespace v1
} // namespace sgl
