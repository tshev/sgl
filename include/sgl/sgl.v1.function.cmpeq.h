#pragma once

namespace sgl {
namespace v1 {

template<typename T>
__m128i cmpeq(const __m128i x, const __m128i y) {
    if constexpr (std::is_same<T, int>::value || std::is_same<T, unsigned int>::value || std::is_same<T, signed int>::value || std::is_same<T, int32_t>::value || std::is_same<T, int32_t>::value) {
        return _mm_cmpeq_epi32(x, y);
    } else if constexpr (std::is_same<T, int16_t>::value || std::is_same<T, int16_t>::value) {
        return _mm_cmpeq_epi16(x, y);
    } else if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value || std::is_same<T, signed char>::value || std::is_same<T, int8_t>::value || std::is_same<T, int8_t>::value) {
        static_assert(sizeof(char) == 1);
        return _mm_cmpeq_epi8(x, y);
    } else {
        return _mm_cmpeq_epi64(x, y);
    }
}

#ifdef __AVX2__
template<typename T>
__m256i cmpeq(const __m256i x, const __m256i y) {
    if constexpr (std::is_same<T, int>::value || std::is_same<T, unsigned int>::value || std::is_same<T, signed int>::value || std::is_same<T, int32_t>::value || std::is_same<T, int32_t>::value) {
        return _mm256_cmpeq_epi32(x, y);
    } else if constexpr (std::is_same<T, int16_t>::value || std::is_same<T, int16_t>::value) {
        return _mm256_cmpeq_epi16(x, y);
    } else if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value || std::is_same<T, signed char>::value || std::is_same<T, int8_t>::value || std::is_same<T, int8_t>::value) {
        static_assert(sizeof(char) == 1);
        return _mm256_cmpeq_epi8(x, y);
    } else {
        return _mm256_cmpeq_epi64(x, y);
    }
}
#endif

template<typename U, typename T>
inline
T cmpeq(const T x, const T y) noexcept {
    return cmpeq<U>(x.value, y.value);
}

} // namespace v1
} // namespace sgl
