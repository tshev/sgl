#pragma once
namespace sgl {
namespace v1 {

template<typename T>
inline
T* uninitialized_construct(T& ptr) {
    return new (reinterpret_cast<void*>(std::addressof(ptr))) T ();
}

template<typename T, typename A, typename... Args>
inline
T* uninitialized_construct(T& ptr, A&& x0, Args&& ...xi) {
    return new (reinterpret_cast<void*>(std::addressof(ptr))) T (std::forward<A>(x0), std::forward<Args>(xi)...);
}

} // namespace v1
} // namespace sgl
