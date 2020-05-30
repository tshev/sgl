#pragma once

namespace sgl {
namespace v1 {

template<typename T>
inline
const char* from_string(const char* first, const char* last, T* value) {
    if constexpr (std::numeric_limits<T>::is_integer) {
        if constexpr (std::is_unsigned<T>::value) {
            return sgl::v1::parse_uint(first, last, value);
        } else {
            return sgl::v1::parse_int(first, last, value);
        }
    } else {
        static_assert(std::numeric_limits<T>::is_integer, "not implemented for not integers");
        return first;
    }
}

} // namespace v1
} // namespace sgl
