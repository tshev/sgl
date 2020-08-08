#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename T>
concept movable = std::is_movable_constructible<T>::value && std::is_movable_assignable<T>::value && std::is_destructible<T>::value;;
)

} // namespace v1
} // namespace sgl
