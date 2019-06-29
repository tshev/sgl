#pragma once

namespace sgl {
namespace v1 {
template<typename T>
inline
bool is_space(T x) {
  return x == ' ' || x == '\t' || x == '\r';
}
} // namespace v1
} // namespace sgl
