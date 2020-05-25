#pragma once

namespace sgl {
namespace v1 {

template<typename It>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
void fill(It first, It last, const SGLValueType(It)& value) {
    // TODO simd-based copying
    while (first != last) {
        *first = value;
        ++first;
    }
}

template<typename T>
struct simd_block_size {
    static constexpr const size_t value = 32;
};

template<typename T>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
void fill(sgl::v1::simd_tag<false> _, T* first, T* last, const T& value) {
    // naive and maybe buggy implemntation
    constexpr size_t block_size = simd_block_size<T>::value / sizeof(T);
    float block[block_size];
    for (size_t i = 0; i < block_size * 4; i += sizeof(T)) {
        *(T*)((char*)block + i) = value;
    }

    size_t n0 = ((char*)last - (char*)first) / block_size / 4 * block_size * 4;
    char* first0 = (char*)first;
    char* last0 = (char*)first0 + n0;
    
    auto val = _mm256_loadu_ps (&block[0]);
    while (first0 != last0) {
        _mm256_storeu_ps((float*)first0, val);
        first0 += block_size * 4;    
    }
    first = (T*) last0;
    while (first != last) {
        *first = value;
        ++first;
    }
}


} // namespace v1
} // namespace sgl
