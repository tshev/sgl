#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename T, typename N>
inline
T pnorm(It first, It last, T value, N p) {
    T powsum = sgl::v1::accumulate(first, last, value, [p](auto r, auto x) {
        return r + sgl::v1::pow(x, p);
    });
    return sgl::v1::pow(powsum, 1.0 / p);
}

} // namespace v1
} // namespace sgl
