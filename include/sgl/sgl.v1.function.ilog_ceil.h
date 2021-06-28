#pragma once

namespace sgl {
namespace v1 {

template<typename N>
inline
N ilog_ceil(N value, N base) {
    N result = 0;

    while (true) {
        N rem = value % base;
        N div = value / base;
        if (!sgl::v1::zero(rem)) break;
        value = std::move(div);
        ++result;
    }

    if (value != 1) {
        ++result;
    }

    while (true) {
        value /= base;
        if (value == 0) break;
        ++result;
    }

    return result;
}

} // namespace v1
} // namespace sgl
