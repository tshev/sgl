#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename F, typename... T>
concept functional_procedure = requires(F f, T&&... args)  { f(args...); };
)

} // namespace v1
} // namespace sgl
