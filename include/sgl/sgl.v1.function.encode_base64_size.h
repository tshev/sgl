#pragma once
namespace sgl {
namespace v1 {

template<typename N>
inline
N encode_base64_size(N n) {
    return ((n + 2) / 3) * 4;
}


template<typename It>
inline
size_t encode_base64_size(It first, It last) {
    const size_t n = sgl::v1::distance(first, last);
    return sgl::v1::encode_base64_size(n);
}


template<typename It>
inline
size_t encode_base64_size(It first, size_t n) {
    return sgl::v1::encode_base64_size(n);
}

}
}
