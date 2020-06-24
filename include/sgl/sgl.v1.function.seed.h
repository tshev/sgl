#pragma once

namespace sgl {
namespace v1 {

template<typename T>
inline
T seed();

#ifdef __RDSEED__
template<>
inline
uint16_t seed<uint16_t>() {
    uint16_t x;
    while (!_rdseed16_step(&x));
    return x;
}

template<>
inline
uint32_t seed<uint32_t>() {
    uint32_t x;
    while(!_rdseed32_step(&x));
    return x;
}

template<>
inline
uint64_t seed<uint64_t>() {
    long long unsigned int x;
    while (!_rdseed64_step(&x));
    return x;
}
#else

template<typename T>
struct __enable_seed {
    static constexpr const bool value = false;
};

template<typename T>
inline
T seed() {
    static_assert(__enable_seed<T>::value, "Enable -mrdrnd");
    return T();
}

#endif
} // namespace v1
} // namespace sgl
