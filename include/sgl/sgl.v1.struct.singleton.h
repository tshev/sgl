#pragma once

namespace sgl {
namespace v1 {
template<typename T>
struct singleton {
  typedef T value_type;

  T value;

  singleton() {}
  singleton(const T& x) : value(x) {}
  singleton(const singleton& x) : value(x.value) {}
  singleton(singleton&&) = default; // noexcept, la-la-lya

  template<typename U>
  operator U() {
    return static_cast<U>(value);
  }

  singleton& operator=(const singleton& x) {
    value = x.value;
    return *this;
  }

  singleton& operator=(const T& x) {
    value = x;
    return *this;
  }

  singleton& operator=(singleton&& x) {
    value = std::move(x.value);
    return *this;
  }

  friend
  inline
  bool operator==(const singleton& x, const singleton& y) {
    return x.value == y.value;
  }

  friend
  inline
  bool operator!=(const singleton& x, const singleton& y) {
    return !(x == y);
  }

  friend
  inline
  bool operator<(const singleton& x, const singleton& y) {
    return x.value < y.value;
  }

  friend
  inline
  bool operator<=(const singleton& x, const singleton& y) {
    return !(y < x);
  }

  friend
  inline
  bool operator>(const singleton& x, const singleton& y) {
    return y < x;
  }

  friend
  inline
  bool operator>=(const singleton& x, const singleton& y) {
    return !(x < y);
  }
};
} // namespace v1
} // namespace sgl
