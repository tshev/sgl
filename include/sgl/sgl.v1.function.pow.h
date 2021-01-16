#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename N>
inline
T pow(T x, N n) {
    if (n == 0) return T(1);
    return sgl::v1::power_semigroup(x, n, sgl::v1::f::multiply<T>());
}

} // namespace v1
} // namespace sgl
