#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename F, typename... A> 
concept predicate = std::is_same<typename std::invoke_result<F, A...>::type, bool>::value;
)   

} // namespace v1
} // namespace sgl
