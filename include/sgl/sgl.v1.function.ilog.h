#pragma once

namespace sgl {
namespace v1 {

template<typename N>
inline
N ilog(N value, N base) {
    N result = 0;
    value /= base;
    while (!sgl::v1::zero(value)) {
        value /= base;
        ++result;
    }
    return result;
}
} // namespace v1
} // namespace sgl
