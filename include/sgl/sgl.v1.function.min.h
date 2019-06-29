#pragma once

namespace sgl {
namespace v1 {
template<typename T>
inline
T& min(T& x, T& y) {
  if (y < x) {
    return y;
  } else {
    return x;
  }
}

template<typename T>
inline
const T& min(const T& x, const T& y) {
  if (y < x) {
    return y;
  } else {
    return x;
  }
}
} // namespace v1
} // namespace sgl
