#pragma once

namespace sgl {
namespace v1 {

template<typename T>
constexpr
size_t strlen(const T& x) {
    if constexpr (std::is_same<char*, T>::value || std::is_array<T>::value || std::is_same<const char*, T>::value ) {
        return std::strlen(x);
    } else {
        return x.size();
    }
}


template<typename T, typename... U>
constexpr
size_t strlen(const T& x, const U&... tail) {
    return sgl::v1::strlen(x) + sgl::v1::strlen(tail...);
}

}
}
