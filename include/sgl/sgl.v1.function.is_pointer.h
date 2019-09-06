#pragma once

namespace sgl {
namespace v1 {

template<typename T>
constexpr
bool is_pointer() {
    return std::is_pointer<T>::value;
}

} // namespace v1
} // namespace sgl
