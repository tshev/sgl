#pragma once

namespace sgl {
namespace v1 {

template<typename N>
inline
N ilog_ceil(N value, N base) {
    N rem = value % base;
    N div = value / base;
    if (!sgl::v1::zero(rem)) {
        N result = sgl::v1::ilog(value, base);
        return ++result;
    }
    N result = 0;
    value = div;
    while (!sgl::v1::zero(value)) {
        rem = value % base;
        div = value / base;
        if (!sgl::v1::zero(value)) {
            break;
        }
        ++result;
        value = div;
    }
    if (value != 0 && rem != 0) {
        ++result;
    }
    return result + sgl::v1::ilog(value, base);
}

} // namespace v1
} // namespace sgl
