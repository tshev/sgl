#pragma once

namespace sgl {
namespace v1 {

template<typename N>
inline
N decode_base64_size(N n) {
    return ((n + 3) / 4) * 3;
}

template<typename It>
inline
size_t decode_base64_size(It first, It last) {
    auto n = sgl::v1::distance(first, last);
    if (n == 0) return 0;
    --last;
    size_t penalty = *last == '=';
    if (last == first) return 0;
    --last;
    penalty += *last == '=';
    return sgl::v1::decode_base64_size(n) - penalty;

}


} // namespace v1
} // namespace sgl
