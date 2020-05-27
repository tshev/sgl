#pragma once
namespace sgl {
namespace v1 {
template<typename T, typename U>
inline
void uninitialized_copy_construct(T& p, const U& x) {
    ::new (const_cast<void*>(static_cast<const volatile void*>(&p)))T(x);
}
} // namespace v1
} // namespace sgl
