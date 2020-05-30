#pragma once

namespace sgl {
namespace v1 {

template<typename T, size_t>
struct simd_vector;

template<>
struct simd_vector<int, 256> {
    typedef int value_type;
    typedef __m256i block_type;
    typedef __m256i register_type;

    __m256i value;

    simd_vector() = default;
    simd_vector(__m256i value) noexcept : value{value} {}
    simd_vector(int value) noexcept : value{_mm256_set1_epi32(value)} {}
    simd_vector(const simd_vector&) = default;

    friend
    inline
    simd_vector operator==(const simd_vector x,  const simd_vector y) noexcept {
        return simd_vector{_mm256_cmpeq_epi32(x.value, y.value)};
    }

    friend
    inline
    simd_vector operator!=(const simd_vector x,  const simd_vector y) noexcept {
        return simd_vector{_mm256_xor_si256((x == y).value, simd_vector(0xFFFFFFFF).value)};
    }
};

template<>
struct simd_vector<int, 128> {
    typedef int value_type;
    typedef __m128i block_type;
    typedef __m128i register_type;

    __m128i value;

    simd_vector() = default;
    simd_vector(__m128i value) noexcept : value{value} {}
    simd_vector(int value) noexcept : value{_mm_set1_epi32(value)} {}
    simd_vector(const simd_vector&) = default;

    friend
    inline
    simd_vector operator==(const simd_vector x,  const simd_vector y) noexcept {
        return simd_vector{_mm_cmpeq_epi32(x.value, y.value)};
    }

    friend
    inline
    simd_vector operator!=(const simd_vector x,  const simd_vector y) noexcept {
        return simd_vector{_mm_xor_si128((x == y).value, simd_vector(0xFFFFFFFF).value)};
    }
};

} // namespace v1
} // namespace sgl
