#pragma once

namespace sgl {
namespace v1 {

template<typename T, size_t Capacity>
struct simd_vector;

template<typename T>
struct simd_vector<T, 128> {
    typedef typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type value_type;
    typedef __m128i block_type;
    typedef block_type register_type;

    block_type value;

    simd_vector() = default;
    simd_vector(block_type value) noexcept : value{value} {}
    simd_vector(T value) noexcept : value{sgl::v1::broadcast<block_type>(value)} {}
    simd_vector(const simd_vector&) = default;

    friend
    inline
    simd_vector operator==(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::cmpeq<T>(x, y);
    }

    friend
    inline
    simd_vector operator!=(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::xor_op(x == y, simd_vector(0xFFFFFFFF));
    }
};

template<>
struct simd_vector<float, 128> {
    typedef float value_type;
    typedef __m128 block_type;
    typedef __m128 register_type;

    __m128 value;

    simd_vector() = default;
    simd_vector(__m128 value) noexcept : value{value} {}
    simd_vector(value_type value) noexcept : value{sgl::v1::broadcast<block_type>(value)} {}
    simd_vector(const simd_vector&) = default;

};


#ifdef __AVX2__
template<typename T>
struct simd_vector<T, 256> {
    typedef typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type value_type;
    typedef __m256i block_type;
    typedef __m256i register_type;

    __m256i value;

    simd_vector() = default;
    simd_vector(__m256i value) noexcept : value{value} {}
    simd_vector(T value) noexcept : value{_mm256_set1_epi32(value)} {}
    simd_vector(const simd_vector&) = default;

    friend
    inline
    simd_vector operator==(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::cmpeq<T>(x, y);
    }

    friend
    inline
    simd_vector operator!=(const simd_vector x,  const simd_vector y) noexcept {
        return sgl::v1::xor_op(x == y, simd_vector(0xFFFFFFFF));
    }
};
#endif

} // namespace v1
} // namespace sgl
