#pragma once
#include <cmath>

namespace sgl {
inline namespace numeric {
  constexpr const double e = 2.71828182845904523536028747135266249775724709369995;
  constexpr const double pi = 3.1415926535897932384626433832795028841971693993751;
} // namespace numeric

namespace functor {
  template<typename T>
  struct max {
    const T& operator()(const T& x, const T& y) const {
      return sgl::v1::max(x, y);
    }
    T& operator()(T& x, T& y) const {
      return sgl::v1::max(x, y);
    }
  };

  template<typename T>
  struct exp {
    T operator()(const T& x) const {
      return ::exp(x);
    }
  };
}

template<typename T>
struct reciprocal {
  T operator()(const T& x) const {
    return T(1) / x;
  }
};


template<typename T, typename N>
T pow(T x, N n) {
  while (even(x)) {
    x *= x;
    half_inplace(n);
  }
  if (n == 1) { return x; }
  --n;
  auto r = x;
  x *= x;
  half_inplace(n);

  while (true) {
    if (odd(n)) {
      r *= x;
      if (n == 1) return r;
    }
    x *= x;
    half_inplace(n);
  }
}

template<typename T, typename N, typename Operation>
T pow(T x, N n, Operation op) {
  while (even(x)) {
    x = op(x, x);
    half_inplace(n);
  }
  if (n == 1) { return x; }
  --n;
  auto r = x;
  x = op(x, x);
  half_inplace(n);

  while (true) {
    if (odd(n)) {
      r *= x;
      if (n == 1) return r;
    }
    x = op(x, x);
    half_inplace(n);
  }
}

template<typename T>
inline
T square(T x) {
  return x * x;
}

template<typename T>
inline
T sigmoid(T x) {
  T exp_value = sgl::exp(x);
  return exp_value / (T{1.0} + exp_value);
}

template<typename T>
inline
T log_sigmoid(T x, T beta) {
  T ebt = sgl::exp(x * beta);
  return ebt / (1.0 + ebt);
}

template<typename T>
inline
T tan_sigmoid(T x) {
  T e = sgl::exp(x);
  T e_inv = 1.0 / e;
  return (e - e_inv) / (e + e_inv);
}

template<typename T>
inline
T tan_sigmoid_derivative(T x) {
  T e = sgl::exp(x);
  T e_inv = 1.0 / e;
  return 1.0 - square(e - e_inv) / square(e + e_inv);
}

template<typename ForwardIterator, typename BinaryOperation>
auto reduce_nonempty(ForwardIterator first, ForwardIterator last, BinaryOperation op) {
  auto result = *first;
  ++first;
  while (first != last) {
    result = op(result, *first);
    ++first;
  }
  return result;
}

template<typename ForwardIterator, typename BinaryOperation, typename Projection>
auto reduce_nonempty(ForwardIterator first, ForwardIterator last, BinaryOperation op, Projection) {
  auto result = projection(*first);
  ++first;
  while (first != last) {
    result = op(result, projection(*first));
    ++first;
  }
  return result;
}


template<typename ForwardIterator, typename BinaryOperation>
auto reduce_nonempty_by_action(ForwardIterator first, ForwardIterator last, BinaryOperation op) {
  if (first == last) {
    throw "Violated precondition: (first != last)";
  }
  auto result = *first;
  ++first;
  while (first != last) {
    op(result, *first);
    ++first;
  }
  return result;
}

template<typename Operation>
struct identity_element {
  typedef typename Operation::result_type result_type;
  typename Operation::result_type operator()() const {
    typedef typename Operation::result_type T;
    return T(0);
  }
};

template<typename T>
struct identity_element<sgl::v1::plus<T>> {
  typedef T result_type;
  T operator()() const {
    return T(0);
  }
};

template<typename T>
struct identity_element<std::multiplies<T>> {
  typedef T result_type;
  T operator()() const {
    return T(1);
  }
};

template<typename T>
inline
typename sgl::identity_element<T>::result_type identity() {
  return sgl::identity_element<T>{}();
}

template<typename ForwardIterator, typename OutputIterator>
// Don't inline!!!!
OutputIterator softmax_with_buffer(ForwardIterator first, ForwardIterator last, OutputIterator out) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;

  std::vector<T> exponents(first, last);
  sgl::v1::for_each(std::begin(exponents), std::end(exponents), [](auto &x) { x = sgl::exp(x); });

  T sum = sgl::accumulate(std::begin(exponents), std::end(exponents), T{0.0});
  return sgl::transform(std::begin(exponents), std::end(exponents), out, [sum](auto ex) { return ex / sum; });
}

template<typename ForwardIterator, typename OutputIterator>
// Don't inline!!!!
OutputIterator softmax_max_with_buffer(ForwardIterator first, ForwardIterator last, OutputIterator out) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;
  if (first == last) return out;

  std::vector<T> exponents(first, last);
  T max = sgl::reduce_nonempty(std::begin(exponents), std::end(exponents), functor::max<T>());
  sgl::v1::for_each(std::begin(exponents), std::end(exponents), [max](auto &x) { x = sgl::exp(x - max); });

  T sum = sgl::accumulate(std::begin(exponents), std::end(exponents), T{0.0});
  return sgl::transform(std::begin(exponents), std::end(exponents), out, [sum](auto ex) { return ex / sum; });
}

template<typename ForwardIterator, typename OutputIterator>
inline
OutputIterator softmax(ForwardIterator first, ForwardIterator last, OutputIterator out) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;
  T sum = sgl::accumulate(first, last, T{0}, [](T result, T x) { return result + sgl::exp(x); });
  return sgl::transform(first, last, out, [sum](auto x) { return sgl::exp(x) / sum; });
}

template<typename ForwardIterator, typename OutputIterator>
inline
OutputIterator softmax_max(ForwardIterator first, ForwardIterator last, OutputIterator out) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;
  if (first == last) {
    return out;
  }
  T max = reduce_nonempty(first, last, functor::max<T>());
  T sum = sgl::accumulate(first, last, T{0}, [max](T result, T x) { return result + sgl::exp(x - max); });
  return sgl::transform(first, last, out, [sum, max](auto x) { return sgl::exp(x - max) / sum; });
}

template<typename ForwardIterator>
void softmax_inplace_max(ForwardIterator first, ForwardIterator last) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;
  if (first == last) return;
  T max = reduce_nonempty(first, last, sgl::functor::max<T>());
  T sum = sgl::accumulate(first, last, sgl::identity<sgl::v1::plus<T>>(), [max](auto result, auto &x) {
      x = sgl::exp(x - max);
      return result + x;
  });
  sgl::v1::for_each(first, last, [sum](T &x) { x /= sum; });
}

template<typename ForwardIterator>
void softmax_inplace(ForwardIterator first, ForwardIterator last) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;
  T sum = sgl::accumulate(first, last, sgl::identity<sgl::v1::plus<T>>(), [](auto result, auto &x) {
      x = sgl::exp(x);
      return result + x;
  });
  sgl::v1::for_each(first, last, [sum](T &x) { x /= sum; });
}

template<typename ForwardIterator>
void softmax_inplace(ForwardIterator first, ForwardIterator last, typename std::iterator_traits<ForwardIterator>::value_type c) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;
  T sum = sgl::accumulate(first, last, sgl::identity<sgl::v1::plus<T>>(), [c](auto result, auto &x) {
      x = sgl::exp(x - c);
      return result + x;
  });
  sgl::v1::for_each(first, last, [sum](T &x) { x /= sum; });
}

template<typename ForwardIterator>
auto minmax_mean(ForwardIterator first, ForwardIterator last) {
  typedef typename std::iterator_traits<ForwardIterator>::value_type T;
  auto minmax = std::minmax_element(first, last);
  return accumulate_dereference(minmax) / T(2);
}
} // namespace sgl
