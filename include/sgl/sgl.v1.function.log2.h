#pragma once
namespace sgl {
namespace v1 {

template <typename T>
inline
T log2(T x) {
    // assert(0 < x);
    if constexpr (std::is_same<T, unsigned char>::value || std::is_same<T, char>::value) {
        return log2<int>(x);
    } else if constexpr (std::is_same<T, unsigned short>::value || std::is_same<T, short>::value) {
        return log2<int>(x);
    } else if constexpr (std::is_same<T, unsigned int>::value || std::is_same<T, int>::value) {
        return T(sizeof(T)) * T(8) - T(1) - __builtin_clz(x);
    } else if constexpr (std::is_same<T, unsigned long>::value || std::is_same<T, long>::value) {
        return T(sizeof(T)) * T(8) - T(1) - __builtin_clzl(x);
    } else if constexpr (std::is_same<T, unsigned long long>::value || std::is_same<T, long long>::value) {
        return T(sizeof(T)) * T(8) - T(1) - __builtin_clzll(x);
    } else {
        return std::log2(x);
    }
    return 0;
}

} // namespace v1
} // namespace sgl
