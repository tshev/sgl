#pragma once

namespace sgl {
namespace v1 {
template<typename T>
inline
T multiplicative_resize(T capacity, T initial_capacity) {
    if (capacity == 0) {
        return initial_capacity;
    }
    return 2 * capacity;
}
} // naemspace v1
} // namespace sgl
