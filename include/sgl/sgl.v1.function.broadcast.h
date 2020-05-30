#pragma once

namespace sgl {
namespace v1 {

template<typename Register, typename T>
Register broadcast(T value) noexcept;

template<>
inline __m128i broadcast<__m128i>(uint8_t x) noexcept  { return _mm_set1_epi8(x); }
template<>
inline __m128i broadcast<__m128i>(int8_t x) noexcept  { return _mm_set1_epi8(x); }
template<>
inline __m128i broadcast<__m128i>(char x) noexcept  { return _mm_set1_epi8(x); }

template<>
inline __m128i broadcast<__m128i>(uint16_t x) noexcept  { return _mm_set1_epi16(x); }
template<>
inline __m128i broadcast<__m128i>(int16_t x) noexcept  { return _mm_set1_epi16(x); }

template<>
inline __m128i broadcast<__m128i>(uint32_t x) noexcept  { return _mm_set1_epi32(x); }
template<>
inline __m128i broadcast<__m128i>(int32_t x) noexcept  { return _mm_set1_epi32(x); }

template<>
inline __m128i broadcast<__m128i>(uint64_t x) noexcept  { return _mm_set1_epi64x(x); }
template<>
inline __m128i broadcast<__m128i>(int64_t x) noexcept  { return _mm_set1_epi64x(x); }

template<>
inline __m128 broadcast<__m128>(float x) noexcept  { return _mm_set1_ps(x); }
template<>
inline __m128d broadcast<__m128d>(double x) noexcept  { return _mm_set1_pd(x); }


#ifdef __AVX2__

template<>
inline __m256i broadcast<__m256i>(uint8_t x) noexcept  { return _mm256_set1_epi8(x); }
template<>
inline __m256i broadcast<__m256i>(int8_t x) noexcept  { return _mm256_set1_epi8(x); }
template<>
inline __m256i broadcast<__m256i>(char x) noexcept  { return _mm256_set1_epi8(x); }

template<>
inline __m256i broadcast<__m256i>(uint16_t x) noexcept  { return _mm256_set1_epi16(x); }
template<>
inline __m256i broadcast<__m256i>(int16_t x) noexcept  { return _mm256_set1_epi16(x); }

template<>
inline __m256i broadcast<__m256i>(uint32_t x) noexcept  { return _mm256_set1_epi32(x); }
template<>
inline __m256i broadcast<__m256i>(int32_t x) noexcept  { return _mm256_set1_epi32(x); }

template<>
inline __m256i broadcast<__m256i>(uint64_t x) noexcept  { return _mm256_set1_epi64x(x); }
template<>
inline __m256i broadcast<__m256i>(int64_t x) noexcept  { return _mm256_set1_epi64x(x); }

#endif
} // namespace v1
} // namespace sgl

