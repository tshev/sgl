#pragma once

inline
__m128d unaligned_load_128(double const* mem_addr) {
  return _mm_loadu_pd(mem_addr);
}

inline
__m128 unaligned_load_128(float const* mem_addr) {
  return _mm_loadu_ps(mem_addr);
}
