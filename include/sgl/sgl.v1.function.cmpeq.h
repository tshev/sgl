#pragma once

namespace sgl {
namespace v1 {

template<size_t>
inline
__m128i cmpeq(const __m128i x, const __m128i y);

template<> inline __m128i cmpeq<1>(const __m128i x, const __m128i y) { return _mm_cmpeq_epi8(x, y); }
template<> inline __m128i cmpeq<2>(const __m128i x, const __m128i y) { return _mm_cmpeq_epi16(x, y); }
template<> inline __m128i cmpeq<4>(const __m128i x, const __m128i y) { return _mm_cmpeq_epi32(x, y); }
template<> inline __m128i cmpeq<8>(const __m128i x, const __m128i y) { return _mm_cmpeq_epi64(x, y); }

inline __m128 cmpeq(const __m128 x, const __m128 y) { return _mm_cmpeq_ps(x, y); }
inline __m128d cmpeq(const __m128d x, const __m128d y) { return _mm_cmpeq_pd(x, y); }


#ifdef __AVX2__
template<size_t>
inline
__m256i cmpeq(const __m256i x, const __m256i y);

template<> inline __m256i cmpeq<1>(const __m256i x, const __m256i y) { return _mm256_cmpeq_epi8(x, y); }
template<> inline __m256i cmpeq<2>(const __m256i x, const __m256i y) { return _mm256_cmpeq_epi16(x, y); }
template<> inline __m256i cmpeq<4>(const __m256i x, const __m256i y) { return _mm256_cmpeq_epi32(x, y); }
template<> inline __m256i cmpeq<8>(const __m256i x, const __m256i y) { return _mm256_cmpeq_epi64(x, y); }

inline __m256 cmpeq(const __m256 x, const __m256 y) { return _mm256_cmp_ps(x, y, _CMP_EQ_OQ); }
inline __m256d cmpeq(const __m256d x, const __m256d y) { return _mm256_cmp_pd(x, y, _CMP_EQ_OQ); }
#endif

template<typename U, typename T>
inline
T cmpeq(const T x, const T y) noexcept {
    return cmpeq<sizeof(U)>(x.value, y.value);
}

template<typename T>
inline
T cmpeq(const T x, const T y) noexcept {
    return cmpeq(x.value, y.value);
}


} // namespace v1
} // namespace sgl
