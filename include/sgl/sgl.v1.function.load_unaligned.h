#pragma once

namespace sgl {
namespace v1 {

inline
__m256i load_unaligned(__m256i const * first) noexcept {
   return  _mm256_loadu_si256(first);
}

inline
__m128i load_unaligned(__m128i const * first) noexcept {
   return  _mm_load_si128(first);
}


template<typename V>
inline
V load_unaligned(V const* first) noexcept {
   return V{load_unaligned(&(first->value))};
}


template<typename V>
inline
V load_unaligned(char const* first) noexcept {
   return  load_unaligned((V*)first);
}

} // namespace v1
} // namespace sgl
