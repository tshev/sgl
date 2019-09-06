#pragma once

namespace sgl {
namespace v1 {

template<typename T>
constexpr
bool is_pod() {
    return std::is_pod<T>::value;
}

} // namespace v1
} // namespace sgl
