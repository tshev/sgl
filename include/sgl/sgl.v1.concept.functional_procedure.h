#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename F, typename... T>
concept functional_procedure = std::is_invocable<F, T...>::value;
)

} // namespace v1
} // namespace sgl
