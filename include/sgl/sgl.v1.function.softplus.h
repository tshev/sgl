#pragma once
namespace sgl {
namespace v1 {

template<typename T>
inline
T softplus(T x) {
  return std::log(T(1.0) + std::exp(x));
}

} // namespace v1
} // namespace sgl
