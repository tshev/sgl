#pragma once

namespace sgl {
namespace v1 {

template<typename N>
inline
N ilog2_ceil(N value) {
    return sgl::v1::ilog2(sgl::v1::ceil_pow2(value));
}

}
}
