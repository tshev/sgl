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
    static constexpr const size_t value = 16;
};

template<typename T>
requires(sgl::v1::forward_iterator(It) && sgl::v1::writable(It))
inline
void fill(sgl::v1::simd_tag<false> _, T* first, T* last, const T& value) {
    constexpr size_t block_size = simd_block_size<T>::value;
    static_assert(sizeof(T) < block_size, "The type should");
    static_assert(block_size % value == 0ull);
    char block[block_size];

    for (size_t i = 0; i < block_size; i += sizeof(T)) {
        *(T*)((char*)block + i) = value;
    }

    constexpr size_t packs_count = 16;
    constexpr size_t step = block_size * packs_count;
    constexpr size_t s1 =  1   * block_size;
    constexpr size_t s2 =  2   * block_size;
    constexpr size_t s3 =  3   * block_size;
    constexpr size_t s4 =  4   * block_size;
    constexpr size_t s5 =  5   * block_size;
    constexpr size_t s6 =  6   * block_size;
    constexpr size_t s7 =  7   * block_size;
    constexpr size_t s8 =  8   * block_size;
    constexpr size_t s9 =  9   * block_size;
    constexpr size_t s10 = 10  * block_size;
    constexpr size_t s11 = 11  * block_size;
    constexpr size_t s12 = 12  * block_size;
    constexpr size_t s13 = 13  * block_size;
    constexpr size_t s14 = 14  * block_size;
    constexpr size_t s15 = 15  * block_size;
    auto batch_size = step * block_size;
    size_t n0 = ((char*)last - (char*)first) / batch_size * batch_size;
    char* first0 = (char*)first;
    char* last0 = (char*)first0 + n0;

    const auto value_packed = __builtin_ia32_loaddqu(&block[0]);
    while (first0 != last0) {
        __builtin_ia32_storedqu(first0,      value_packed);
        __builtin_ia32_storedqu(first0 + s1, value_packed);
        __builtin_ia32_storedqu(first0 + s2, value_packed);
        __builtin_ia32_storedqu(first0 + s3, value_packed);
        __builtin_ia32_storedqu(first0 + s4, value_packed);
        __builtin_ia32_storedqu(first0 + s5, value_packed);
        __builtin_ia32_storedqu(first0 + s6, value_packed);
        __builtin_ia32_storedqu(first0 + s7, value_packed);
        __builtin_ia32_storedqu(first0 + s8, value_packed);
        __builtin_ia32_storedqu(first0 + s9, value_packed);
        __builtin_ia32_storedqu(first0 + s10, value_packed);
        __builtin_ia32_storedqu(first0 + s11, value_packed);
        __builtin_ia32_storedqu(first0 + s12, value_packed);
        __builtin_ia32_storedqu(first0 + s13, value_packed);
        __builtin_ia32_storedqu(first0 + s14, value_packed);
        __builtin_ia32_storedqu(first0 + s15, value_packed);
        first0 += step;
    }
    first = (T*) last0;
    while (first != last) {
        *first = value;
        ++first;
    }
}

} // namespace v1
} // namespace sgl
