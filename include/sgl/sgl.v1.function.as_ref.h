#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename U>
T& as_ref(U data) {
    static_assert(std::is_pointer<U>::value, "Value should be a pointer");
    return *(T*)data;
}

} // namespace v1
} // namespace sgl
