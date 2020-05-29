#pragma once

namespace sgl {
namespace v1 {

inline
void stream_aligned(__m256i* first, __m256i value) noexcept {
    _mm256_stream_si256(first, value);
}

inline
void stream_aligned(__m128i* first, __m128i value) noexcept {
    _mm_stream_si128(first, value);
}

template<typename V>
inline
void stream_aligned(V* first, V value) noexcept {
    stream_aligned(&(first->value), value.value);
}

} // namespace v1
} // namespace sgl
