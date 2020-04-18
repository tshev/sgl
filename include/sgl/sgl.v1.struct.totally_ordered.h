#pragma once
namespace sgl {
namespace v1 {

template<typename T>
struct totally_ordered {
  friend
  inline
  bool operator>(const T& x, const T& y) {
    return y < x;
  }

  friend
  inline
  bool operator<=(const T& x, const T& y) {
    return !(y < x);
  }

  friend
  inline
  bool operator>=(const T& x, const T& y) {
    return !(x < y);
  }
}; // struct totally_ordered

} // namespace v1
} // namespace sgl
