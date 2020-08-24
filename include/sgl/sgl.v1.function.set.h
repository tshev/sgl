#pragma once

namespace sgl {
namespace v1 {

template<typename T, sgl::v1::simd_mode mode, size_t N>
struct _set;

template<sgl::v1::simd_mode mode>
struct _set<uint8_t, mode, 128> {

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15) const noexcept  {
    return _mm_set_epi8(x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14) const noexcept  {
    return _mm_set_epi8(0, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13) const noexcept  {
    return _mm_set_epi8(0, 0, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12) const noexcept  {
    return _mm_set_epi8(0, 0, 0, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x04, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x03, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01, uint8_t x02) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x02, x01, x00);
}

__m128i operator()(uint8_t x00, uint8_t x01) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x01, x00);
}

__m128i operator()(uint8_t x00) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x00);
}
};

#ifdef __AVX__
template<sgl::v1::simd_mode mode>
struct _set<uint8_t, mode, 256> {
__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24, uint8_t x25, uint8_t x26, uint8_t x27, uint8_t x28, uint8_t x29, uint8_t x30, uint8_t x31) const noexcept  {
    return _mm256_set_epi8(x31, x30, x29, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24, uint8_t x25, uint8_t x26, uint8_t x27, uint8_t x28, uint8_t x29, uint8_t x30) const noexcept  {
    return _mm256_set_epi8(0, x30, x29, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24, uint8_t x25, uint8_t x26, uint8_t x27, uint8_t x28, uint8_t x29) const noexcept  {
    return _mm256_set_epi8(0, 0, x29, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24, uint8_t x25, uint8_t x26, uint8_t x27, uint8_t x28) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}


__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24, uint8_t x25, uint8_t x26, uint8_t x27) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}


__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24, uint8_t x25, uint8_t x26) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24, uint8_t x25) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23, uint8_t x24) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22, uint8_t x23) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21, uint8_t x22) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20, uint8_t x21) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19, uint8_t x20) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t, uint8_t x19) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18, uint8_t x19) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17, uint8_t x18) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16, uint8_t x17) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15, uint8_t x16) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14, uint8_t x15) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13, uint8_t x14) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12, uint8_t x13) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11, uint8_t x12) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10, uint8_t x11) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09, uint8_t x10) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08, uint8_t x09) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07, uint8_t x08) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06, uint8_t x07) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05, uint8_t x06) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04, uint8_t x05) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03, uint8_t x04) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x04, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02, uint8_t x03) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x03, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01, uint8_t x02) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x02, x01, x00);
}

__m256i operator()(uint8_t x00, uint8_t x01) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x01, x00);
}

__m256i operator()(uint8_t x00) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x00);
}

};

template<sgl::v1::simd_mode mode>
struct _set<int8_t, mode, 256> {
__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24, int8_t x25, int8_t x26, int8_t x27, int8_t x28, int8_t x29, int8_t x30, int8_t x31) const noexcept  {
    return _mm256_set_epi8(x31, x30, x29, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24, int8_t x25, int8_t x26, int8_t x27, int8_t x28, int8_t x29, int8_t x30) const noexcept  {
    return _mm256_set_epi8(0, x30, x29, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24, int8_t x25, int8_t x26, int8_t x27, int8_t x28, int8_t x29) const noexcept  {
    return _mm256_set_epi8(0, 0, x29, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24, int8_t x25, int8_t x26, int8_t x27, int8_t x28) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24, int8_t x25, int8_t x26, int8_t x27) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24, int8_t x25, int8_t x26) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24, int8_t x25) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23, int8_t x24) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22, int8_t x23) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21, int8_t x22) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20, int8_t x21) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19, int8_t x20) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t, int8_t x19) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18, int8_t x19) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17, int8_t x18) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x18, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16, int8_t x17) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x17, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15, int8_t x16) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x16, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x04, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x03, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01, int8_t x02) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x02, x01, x00);
}

__m256i operator()(int8_t x00, int8_t x01) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x01, x00);
}

__m256i operator()(int8_t x00) const noexcept  {
    return _mm256_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x00);
}
};
#endif

template<sgl::v1::simd_mode mode>
struct _set<int8_t, mode, 128> {

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14, int8_t x15) const noexcept  {
    return _mm_set_epi8(x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13, int8_t x14) const noexcept  {
    return _mm_set_epi8(0, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12, int8_t x13) const noexcept  {
    return _mm_set_epi8(0, 0, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11, int8_t x12) const noexcept  {
    return _mm_set_epi8(0, 0, 0, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10, int8_t x11) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09, int8_t x10) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08, int8_t x09) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07, int8_t x08) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06, int8_t x07) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05, int8_t x06) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, x06, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04, int8_t x05) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x05, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03, int8_t x04) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x04, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02, int8_t x03) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x03, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01, int8_t x02) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x02, x01, x00);
}

__m128i operator()(int8_t x00, int8_t x01) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x01, x00);
}

__m128i operator()(int8_t x00) const noexcept  {
    return _mm_set_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x00);
}

};

template<sgl::v1::simd_mode mode>
struct _set<uint16_t, mode, 128> {
    __m128i operator()(uint16_t x00) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, 0, 0, 0, x00);
    }

    __m128i operator()(uint16_t x00, uint16_t x01) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, 0, 0, x01, x00);
    }

    __m128i operator()(uint16_t x00, uint16_t x01, uint16_t x02) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, 0, x02, x01, x00);
    }

    __m128i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, x03, x02, x01, x00);
    }

    __m128i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04) const noexcept  {
        return _mm_set_epi16(0, 0, 0, x04, x03, x02, x01, x00);
    }

    __m128i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05) const noexcept  {
        return _mm_set_epi16(0, 0, x05, x04, x03, x02, x01, x00);
    }

    __m128i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06) const noexcept  {
        return _mm_set_epi16(0, x06, x05, x04, x03, x02, x01, x00);
    }

    __m128i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07) const noexcept  {
        return _mm_set_epi16(x07, x06, x05, x04, x03, x02, x01, x00);
    }
};

template<sgl::v1::simd_mode mode>
struct _set<int16_t, mode, 128> {
    __m128i operator()(int16_t x00) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, 0, 0, 0, x00);
    }

    __m128i operator()(int16_t x00, int16_t x01) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, 0, 0, x01, x00);
    }

    __m128i operator()(int16_t x00, int16_t x01, int16_t x02) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, 0, x02, x01, x00);
    }

    __m128i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03) const noexcept  {
        return _mm_set_epi16(0, 0, 0, 0, x03, x02, x01, x00);
    }

    __m128i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04) const noexcept  {
        return _mm_set_epi16(0, 0, 0, x04, x03, x02, x01, x00);
    }

    __m128i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05) const noexcept  {
        return _mm_set_epi16(0, 0, x05, x04, x03, x02, x01, x00);
    }

    __m128i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06) const noexcept  {
        return _mm_set_epi16(0, x06, x05, x04, x03, x02, x01, x00);
    }

    __m128i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07) const noexcept  {
        return _mm_set_epi16(x07, x06, x05, x04, x03, x02, x01, x00);
    }
};

#ifdef __AVX__

template<sgl::v1::simd_mode mode>
struct _set<uint16_t, mode, 256> {

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08, uint16_t x09, uint16_t x10, uint16_t x11, uint16_t x12, uint16_t x13, uint16_t x14, uint16_t x15) const noexcept  {
    return _mm256_set_epi16(x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08, uint16_t x09, uint16_t x10, uint16_t x11, uint16_t x12, uint16_t x13, uint16_t x14) const noexcept  {
    return _mm256_set_epi16(0, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08, uint16_t x09, uint16_t x10, uint16_t x11, uint16_t x12, uint16_t x13) const noexcept  {
    return _mm256_set_epi16(0, 0, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08, uint16_t x09, uint16_t x10, uint16_t x11, uint16_t x12) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08, uint16_t x09, uint16_t x10, uint16_t x11) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08, uint16_t x09, uint16_t x10) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08, uint16_t x09) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07, uint16_t x08) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06, uint16_t x07) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05, uint16_t x06) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04, uint16_t x05) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03, uint16_t x04) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x04, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02, uint16_t x03) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x03, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01, uint16_t x02) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x02, x01, x00);
}

__m256i operator()(uint16_t x00, uint16_t x01) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x01, x00);
}

__m256i operator()(uint16_t x00) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x00);
}
};

template<sgl::v1::simd_mode mode>
struct _set<int16_t, mode, 256> {

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08, int16_t x09, int16_t x10, int16_t x11, int16_t x12, int16_t x13, int16_t x14, int16_t x15) const noexcept  {
    return _mm256_set_epi16(x15, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08, int16_t x09, int16_t x10, int16_t x11, int16_t x12, int16_t x13, int16_t x14) const noexcept  {
    return _mm256_set_epi16(0, x14, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08, int16_t x09, int16_t x10, int16_t x11, int16_t x12, int16_t x13) const noexcept  {
    return _mm256_set_epi16(0, 0, x13, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08, int16_t x09, int16_t x10, int16_t x11, int16_t x12) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, x12, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08, int16_t x09, int16_t x10, int16_t x11) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, x11, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08, int16_t x09, int16_t x10) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, x10, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08, int16_t x09) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, x09, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07, int16_t x08) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, x08, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06, int16_t x07) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, x07, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05, int16_t x06) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, x06, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04, int16_t x05) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x05, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03, int16_t x04) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x04, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02, int16_t x03) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x03, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01, int16_t x02) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x02, x01, x00);
}

__m256i operator()(int16_t x00, int16_t x01) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x01, x00);
}

__m256i operator()(int16_t x00) const noexcept  {
    return _mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x00);
}
};
#endif

template<sgl::v1::simd_mode mode>
struct _set<int32_t, mode, 128> {
    __m128i operator()(int32_t x00) const noexcept  {
        return _mm_set_epi32(0, 0, 0, x00);
    }

    __m128i operator()(int32_t x00, int32_t x01) const noexcept  {
        return _mm_set_epi32(0, 0, x01, x00);
    }

    __m128i operator()(int32_t x00, int32_t x01, int32_t x02) const noexcept  {
        return _mm_set_epi32(0, x02, x01, x00);
    }

    __m128i operator()(int32_t x00, int32_t x01, int32_t x02, int32_t x03) const noexcept  {
        return _mm_set_epi32(x03, x02, x01, x00);
    }
};

template<sgl::v1::simd_mode mode>
struct _set<uint32_t, mode, 128> {
    __m128i operator()(uint32_t x00) const noexcept  {
        return _mm_set_epi32(0, 0, 0, x00);
    }

    __m128i operator()(uint32_t x00, uint32_t x01) const noexcept  {
        return _mm_set_epi32(0, 0, x01, x00);
    }

    __m128i operator()(uint32_t x00, uint32_t x01, uint32_t x02) const noexcept  {
        return _mm_set_epi32(0, x02, x01, x00);
    }

    __m128i operator()(uint32_t x00, uint32_t x01, uint32_t x02, uint32_t x03) const noexcept  {
        return _mm_set_epi32(x03, x02, x01, x00);
    }
};

#ifdef __AVX__
template<sgl::v1::simd_mode mode>
struct _set<int32_t, mode, 256> {
    __m256i operator()(int32_t x00) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, x00);
    }

    __m256i operator()(int32_t x00, int32_t x01) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, 0, 0, x01, x00);
    }

    __m256i operator()(int32_t x00, int32_t x01, int32_t x02) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, 0, x02, x01, x00);
    }

    __m256i operator()(int32_t x00, int32_t x01, int32_t x02, int32_t x03) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, x03, x02, x01, x00);
    }
};

template<sgl::v1::simd_mode mode>
struct _set<uint32_t, mode, 256> {
    __m256i operator()(uint32_t x00) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, x00);
    }

    __m256i operator()(uint32_t x00, uint32_t x01) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, 0, 0, x01, x00);
    }

    __m256i operator()(uint32_t x00, uint32_t x01, uint32_t x02) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, 0, x02, x01, x00);
    }

    __m256i operator()(uint32_t x00, uint32_t x01, uint32_t x02, uint32_t x03) const noexcept  {
        return _mm256_set_epi32(0, 0, 0, 0, x03, x02, x01, x00);
    }
};
#endif

template<sgl::v1::simd_mode mode>
struct _set<int64_t, mode, 128> {
    __m128i operator()(int64_t x00) const noexcept  {
        return _mm_set_epi64x(int64_t(0), x00);
    }

    __m128i operator()(int64_t x00, int64_t x01) const noexcept  {
        return _mm_set_epi64x(x01, x00);
    }
};

template<sgl::v1::simd_mode mode>
struct _set<uint64_t, mode, 128> {
    __m128i operator()(uint64_t x00) const noexcept  {
        return _mm_set_epi64x(int64_t(0), x00);
    }

    __m128i operator()(uint64_t x00, uint64_t x01) const noexcept  {
        return _mm_set_epi64x(x01, x00);
    }
};

#ifdef __AVX__
template<sgl::v1::simd_mode mode>
struct _set<int64_t, mode, 256> {
    __m256i operator()(int64_t x00) const noexcept  {
        return _mm256_set_epi64x(int64_t(0), int64_t(0),int64_t(0), x00);
    }

    __m256i operator()(int64_t x00, int64_t x01) const noexcept  {
        return _mm256_set_epi64x(int64_t(0), int64_t(0), x01, x00);
    }

    __m256i operator()(int64_t x00, int64_t x01, int64_t x02) const noexcept  {
        return _mm256_set_epi64x(int64_t(0), x02, x01, x00);
    }

    __m256i operator()(int64_t x00, int64_t x01, int64_t x02, int64_t x03) const noexcept  {
        return _mm256_set_epi64x(x03, x02, x01, x00);
    }
};

template<sgl::v1::simd_mode mode>
struct _set<uint64_t, mode, 256> {
    __m256i operator()(uint64_t x00) const noexcept  {
        return _mm256_set_epi64x(uint64_t(0), uint64_t(0),uint64_t(0), x00);
    }

    __m256i operator()(uint64_t x00, uint64_t x01) const noexcept  {
        return _mm256_set_epi64x(uint64_t(0), uint64_t(0), x01, x00);
    }

    __m256i operator()(uint64_t x00, uint64_t x01, uint64_t x02) const noexcept  {
        return _mm256_set_epi64x(uint64_t(0), x02, x01, x00);
    }

    __m256i operator()(uint64_t x00, uint64_t x01, uint64_t x02, uint64_t x03) const noexcept  {
        return _mm256_set_epi64x(x03, x02, x01, x00);
    }
};
#endif

template<sgl::v1::simd_mode mode = sgl::v1::simd_mode::unaligned, size_t N = 128, typename... T>
inline
auto set(T... value) noexcept {
    return sgl::v1::_set<typename sgl::v1::vararg0<T...>::type, mode, N>()(value...);
}

} // namespace v1
} // namespace sgl
