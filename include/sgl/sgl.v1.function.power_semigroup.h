#pragma once
namespace sgl {
namespace v1 {
template<typename T>
inline
T half(T x) {
  return x >> 1;
}

template<typename T>
inline
void half_inplace(T &x) {
  x >>= 1;
}


template<typename T>
inline
bool even(const T& x) {
  return (x & 1) == 0;
}


template<typename T>
inline
bool odd(const T& x) {
  return (x & 1) != 0;
}

template<typename T, typename N, typename Operation>
T power_accumulate_semigroup(T r, T x, N n, Operation op) {
  if (n == 0) {
    return r;
  }
  while (true) {
    if (odd(n)) {
      r = op(r, x);
      if (n == 1) return r;
    }
    half_inplace(n);
    x = op(x, x);
  }
}

template<typename T, typename N, typename Operation>
T power_semigroup(T x, N n, Operation op) {
  while (even(n)) {
    x = op(x, x);
    half_inplace(n);
  }
  if (n == 1) return x;
  --n;
  return power_accumulate_semigroup(x, op(x, x), half(n), op);
}

} // namespace v1
} // namespace sgl
