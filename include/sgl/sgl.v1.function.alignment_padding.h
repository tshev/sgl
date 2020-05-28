#pragma once
namespace sgl {
namespace v1 {

template<typename T>
inline
constexpr
T alignment_padding(T addr, T alignment) {
    return (alignment  - (addr & (alignment - T(1)))) & (alignment - T(1));
}

}
}
