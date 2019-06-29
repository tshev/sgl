#pragma once
namespace sgl {
namespace v1 {

double inner_product_n(const double* first0, size_t n, const double* first1, double r) {
  constexpr uint8_t mask = ~static_cast<uint8_t>(0u);
  size_t n4 = ((n >> 1u) << 1u);

  const double* last0 = first0 + n4;
  const double* last1 = first0 + n;
  double tmp[2];

  while (first0 != last0) {
    __m128d a = _mm_loadu_pd(first0);
    __m128d b = _mm_loadu_pd(first1);
    __m128d c = _mm_dp_pd(a, b, mask);
    _mm_store_pd(tmp, c); // aligned
    r += tmp[0];
    first0 += 2u;
    first1 += 2u;
  }

  while (first0 != last1) {
    r += *first0 * *first1;
    ++first0;
    ++first1;
  }
  return r;
}
} // namespace v1
} // namespace sgl
