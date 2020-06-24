#pragma once

namespace sgl {
namespace v1 {

template<typename T>
inline
T rand();

#ifdef __RDRND__
template<>
inline
uint16_t rand<uint16_t>() {
    uint16_t x;
    while(!_rdrand16_step(&x));
    return x;
}

template<>
inline
uint32_t rand<uint32_t>() {
    uint32_t x;
    while(!_rdrand32_step(&x));
    return x;
}

template<>
inline
uint64_t rand<uint64_t>() {
    long long unsigned int x;
    while (!_rdrand64_step(&x));
    return x;
}

#else

template<typename T>
struct __enable_rand {
    static constexpr const bool value = false;
};

template<typename T>
inline
T rand() {
    static_assert(__enable_rand<T>::value, "Enable -mrdrnd");
    return T();
}

#endif
} // namespace v1
} // namespace sgl
