#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename T>
concept regular = semiregular<T> && requires(const T& x, const T& y, bool& r) { r = (x == y); };
)

} // namespace v1
} // namespace sgl
