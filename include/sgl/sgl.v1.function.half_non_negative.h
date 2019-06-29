#pragma once
namespace sgl {
namespace v1 {
template<typename T>
T half_non_negative(const T& x) {
  return x >> 1ul;
}
} // namespace v1
} // namespace sgl
