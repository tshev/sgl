#pragma once

namespace sgl {
namespace v1 {
template<typename T>
inline
T& max(T& x, T& y) {
  if (y < x) {
    return x;
  } else {
    return y;
  }
}

template<typename T>
inline
const T& max(const T& x, const T& y) {
  if (y < x) {
    return x;
  } else {
    return y;
  }
}
} // namespace v1
} // namespace sgl
