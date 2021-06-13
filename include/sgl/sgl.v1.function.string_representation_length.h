#pragma once
namespace sgl {
namespace v1 {

template<typename N>
N string_representation_length(N x, N base) {
    auto n = sgl::v1::ilog_ceil(x, base);
    if (x <= 0) ++n;
    return n;
}

}
}
