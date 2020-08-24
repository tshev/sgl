#pragma once

namespace sgl {
namespace v1 {

template<typename T, sgl::v1::simd_mode mode, size_t N>
struct _broadcast;

template<sgl::v1::simd_mode mode>
struct _broadcast<uint8_t, mode, 128> {
    __m128i operator()(uint8_t x) const noexcept  { return _mm_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int8_t, mode, 128> {
    __m128i operator()(int8_t x) const noexcept  { return _mm_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<char, mode, 128> {
    __m128i operator()(char x) const noexcept  { return _mm_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint16_t, mode, 128> {
    __m128i operator()(uint16_t x) const noexcept  { return _mm_set1_epi16(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int16_t, mode, 128> {
    __m128i operator()(int16_t x) const noexcept  { return _mm_set1_epi16(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint32_t, mode, 128> {
    __m128i operator()(uint32_t x) const noexcept  { return _mm_set1_epi32(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int32_t, mode, 128> {
    __m128i operator()(int32_t x) const noexcept  { return _mm_set1_epi32(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint64_t, mode, 128> {
    __m128i operator()(uint64_t x) const noexcept  { return _mm_set1_epi64x(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int64_t, mode, 128> {
    __m128i operator()(int64_t x) const noexcept  { return _mm_set1_epi64x(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<float, mode, 128> {
    __m128 operator()(float x) const noexcept  { return _mm_set1_ps(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<double, mode, 128> {
    __m128d operator()(double x) const noexcept  { return _mm_set1_pd(x); }
};

#ifdef __AVX__
template<sgl::v1::simd_mode mode>
struct _broadcast<uint8_t, mode, 256> {
    __m256i operator()(uint8_t x) const noexcept  { return _mm256_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int8_t, mode, 256> {
    __m256i operator()(int8_t x) const noexcept  { return _mm256_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<char, mode, 256> {
    __m256i operator()(char x) const noexcept  { return _mm256_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint16_t, mode, 256> {
    __m256i operator()(uint16_t x) const noexcept  { return _mm256_set1_epi16(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int16_t, mode, 256> {
    __m256i operator()(int16_t x) const noexcept  { return _mm256_set1_epi16(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint32_t, mode, 256> {
    __m256i operator()(uint32_t x) const noexcept  { return _mm256_set1_epi32(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int32_t, mode, 256> {
    __m256i operator()(int32_t x) const noexcept  { return _mm256_set1_epi32(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint64_t, mode, 256> {
    __m256i operator()(uint64_t x) const noexcept  { return _mm256_set1_epi64x(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int64_t, mode, 256> {
    __m256i operator()(int64_t x) const noexcept  { return _mm256_set1_epi64x(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<float, mode, 256> {
    __m256 operator()(float x) const noexcept  { return _mm256_set1_ps(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<double, mode, 256> {
    __m256d operator()(double x) const noexcept  { return _mm256_set1_pd(x); }
};
#endif

#ifdef __AVX512F__
template<sgl::v1::simd_mode mode>
struct _broadcast<uint8_t, mode, 512> {
    __m512i operator()(uint8_t x) const noexcept  { return _mm512_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int8_t, mode, 512> {
    __m512i operator()(int8_t x) const noexcept  { return _mm512_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<char, mode, 512> {
    __m512i operator()(char x) const noexcept  { return _mm512_set1_epi8(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint16_t, mode, 512> {
    __m512i operator()(uint16_t x) const noexcept  { return _mm512_set1_epi16(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int16_t, mode, 512> {
    __m512i operator()(int16_t x) const noexcept  { return _mm512_set1_epi16(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint32_t, mode, 512> {
    __m512i operator()(uint32_t x) const noexcept  { return _mm512_set1_epi32(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int32_t, mode, 512> {
    __m512i operator()(int32_t x) const noexcept  { return _mm512_set1_epi32(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<uint64_t, mode, 512> {
    __m512i operator()(uint64_t x) const noexcept  { return _mm512_set1_epi64x(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<int64_t, mode, 512> {
    __m512i operator()(int64_t x) const noexcept  { return _mm512_set1_epi64x(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<float, mode, 512> {
    __m512 operator()(float x) const noexcept  { return _mm512_set1_ps(x); }
};

template<sgl::v1::simd_mode mode>
struct _broadcast<double, mode, 512> {
    __m512d operator()(double x) const noexcept  { return _mm512_set1_pd(x); }
};
#endif

template<sgl::v1::simd_mode mode = sgl::v1::simd_mode::unaligned, size_t N = 128, typename T>
inline
auto broadcast(T value) noexcept {
    return sgl::v1::_broadcast<T, mode, N>()(value);
}

} // namespace v1
} // namespace sgl

