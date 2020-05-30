#pragma once

namespace sgl {
namespace v1 {

inline
__m128i xor_op(const __m128i x, const __m128i y) noexcept {
    return _mm_xor_si128(x, y);
}

inline
__m256i xor_op(const __m256i x, const __m256i y) noexcept {
    return _mm256_xor_si256(x, y);
}

template<typename T>
inline
T xor_op(const T x, const T y) noexcept {
    return xor_op(x.value, y.value);
}


} // namespace v1
} // namespace sgl
