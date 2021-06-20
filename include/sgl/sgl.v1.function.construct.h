#pragma once

namespace sgl {
namespace v1 {

template<class T>
inline
constexpr void construct(T* p) {
    ::new (const_cast<void*>(static_cast<const volatile void*>(p)))T();
}

template<class T>
inline
constexpr void construct(T* p, const T& value) {
    ::new (const_cast<void*>(static_cast<const volatile void*>(p)))T(value);
}


template<class T, class... Args>
inline
constexpr void construct(T* p, Args&&... args ) {
    ::new (const_cast<void*>(static_cast<const volatile void*>(p)))T(std::forward<Args>(args)...);
}


} // namespace v1
} // namespace sgl
