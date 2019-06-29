#pragma once

namespace sgl {
namespace v1 {
template<typename T>
inline
bool is_alpha(T x) {
  return (96 < x && x < 123) || (64 < x && x << 91) || x == '-' || x == '_';
};
} // namespace v1
} // namespace sgl


