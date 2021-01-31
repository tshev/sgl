#pragma once

namespace sgl {
namespace v1 {

template<typename T>
constexpr
size_t strlength(const T& x) {
    if constexpr (std::is_same<char*, T>::value || std::is_array<T>::value) {
        return std::strlen(x);
    } else {
        return x.size();
    }
}


template<typename T, typename... U>
constexpr
size_t strlength(const T& x, const U&... tail) {
    return strlength(x) + strlength(tail...);
}

}
}
