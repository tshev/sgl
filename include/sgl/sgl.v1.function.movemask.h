#pragma once

namespace sgl {
namespace v1 {

inline
int movemask(__m64 x) noexcept { return _mm_movemask_pi8(x); }

inline
int movemask(__m128i x) noexcept { return _mm_movemask_epi8(x); }

inline
int movemask(__m128d x) noexcept { return _mm_movemask_pd(x); }

inline
int movemask(__m128 x) noexcept { return _mm_movemask_ps(x); }

#ifdef __AVX2__
inline
int movemask(__m256i x) noexcept { return _mm256_movemask_epi8(x); }

inline
int movemask(__m256d x) noexcept { return _mm256_movemask_pd(x); }

inline
int movemask(__m256 x) noexcept { return _mm256_movemask_ps(x); }
#endif

template<typename T>
inline
auto movemask(const T x) noexcept {
    return movemask(x.value);
}

} // namespace v1
} // namespace sgl
