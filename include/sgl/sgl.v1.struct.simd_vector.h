#pragma once

namespace sgl {
namespace v1 {

template<typename T, size_t>
struct simd_vector;

template<>
struct simd_vector<int, 256> {
    typedef int value_type;
    typedef __m256i block_type;

    __m256i value;
};

template<>
struct simd_vector<int, 128> {
    typedef int value_type;
    typedef __m128i block_type;

    __m128i value;
};

} // namespace v1
} // namespace sgl
