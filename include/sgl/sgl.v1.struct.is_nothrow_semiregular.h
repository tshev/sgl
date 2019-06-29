#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct is_nothrow_semiregular {
    static constexpr const bool value = std::is_nothrow_copy_constructible<T>::value && std::is_nothrow_copy_assignable<T>::value;
};

} // namespace v1
} // namespace sgl
