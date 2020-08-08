#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename T>
concept semiregular = std::is_copy_constructible<T>::value && std::is_copy_assignable<T>::value && std::is_destructible<T>::value;;
)

} // namespace v1
} // namespace sgl
