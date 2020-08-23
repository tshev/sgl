#pragma once

namespace sgl {
namespace v1 {

template<bool a = false, size_t N = sgl::v1::max_simd_vector_size<uint8_t>::value * 8>
struct simd_tag {
    static constexpr const bool aligned = a;
    static constexpr size_t digit_capacity = N;

};


} // namespace v1
} // namespace sgl
