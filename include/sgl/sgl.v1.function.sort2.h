#pragma once

namespace sgl {
namespace v1 {

template<typename T>
inline
void sort2(T& x, T& y) {
    if (y < x) {
        std::swap(x, y);
    }
}

template<typename T, typename R>
inline
void sort2(T& x, T& y, R r) {
    // precondition: weak_strict_ordering(r)
    if (r(y, x)) {
        std::swap(x, y);
    }
}

} // namespace v1
} // namespace sgl
