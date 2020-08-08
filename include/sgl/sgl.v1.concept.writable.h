#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename I, typename T = SGLValueType(I)>
concept writable = requires(I x, const T& v)  { *x = v; };
)

} // namespace v1
} // namespace sgl
