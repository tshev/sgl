#pragma once

namespace sgl {
namespace v1 {

template<typename N0, typename N1>
inline
N0 pow(N0 x, N1 n) {
    if (n == 0) return N0(1);
    return sgl::v1::power_semigroup(x, n, sgl::v1::f::multiply<N0>());
}

} // namespace v1
} // namespace sgl
