#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct _strlen {
    size_t operator()(const T& x) const {
        return x.size();
    }
};


template<>
struct _strlen<const char*> {
    constexpr size_t operator()(const char* x) const {
        size_t n = 0;
        while (*x) { ++n; ++x; }
        return n;
    }
};

template<typename T>
constexpr
size_t strlen(T const& x) {
    return sgl::v1::_strlen<T>()(x);
}


template<typename T, typename... U>
constexpr
size_t strlen(const T& x, const U&... tail) {
    return sgl::v1::strlen(x) + sgl::v1::strlen(tail...);
}

}  // namespace v1
}  // namespace sgl
