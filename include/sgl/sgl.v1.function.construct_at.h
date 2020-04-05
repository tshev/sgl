#pragma once

namespace sgl {
namespace v1 {
template<class T, class... Args>
constexpr T* construct_at( T* p, Args&&... args ) {
    return ::new (const_cast<void*>(static_cast<const volatile void*>(p)))T(std::forward<Args>(args)...);
}
}
}
