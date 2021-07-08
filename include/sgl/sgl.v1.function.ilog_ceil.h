#pragma once

namespace sgl {
namespace v1 {


template<typename N>
inline
N ilog_ceil(N value, N base) {
    N result = 1;
    --value;
    while (true) {
        value /= base;
        if (sgl::v1::zero(value)) break;
        ++result;
    }
    return result;
}

} // namespace v1
} // namespace sgl
