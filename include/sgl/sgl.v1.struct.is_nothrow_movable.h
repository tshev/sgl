#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct is_nothrow_movable {
    static constexpr const bool value = std::is_nothrow_move_constructible<T>::value && std::is_nothrow_move_assignable<T>::value;
};

} // namespace v1
} // namespace sgl
