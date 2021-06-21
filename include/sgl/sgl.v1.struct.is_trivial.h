#pragma once
namespace sgl {
namespace v1 {
template<typename T>
struct is_trivial {
    static constexpr bool value = std::is_trivially_constructible<T>::value && std::is_nothrow_constructible<T>::value && std::is_trivial<T>::value;
};
} // namespace v1
} // namespace sgl
