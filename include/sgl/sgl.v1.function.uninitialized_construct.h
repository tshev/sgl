#pragma once
namespace sgl {
namespace v1 {

template<typename T>
inline
T* uninitialized_construct(T& ptr) {
    return sgl::v1::construct_at(std::addressof(ptr));
}


template<typename T, typename A, typename... Args>
inline
T* uninitialized_construct(T& ptr, A&& x0, Args&& ...xi) {
    return sgl::v1::construct_at(std::addressof(ptr), std::forward<A>(x0), std::forward<Args>(xi)...);
}

} // namespace v1
} // namespace sgl
