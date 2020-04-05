#pragma once

namespace sgl {
namespace v1 {

template<typename T>
inline
T count_digits(T x, T k) {
    T r = 0;
    while (true) {
        ++r;
        x /= k;
        if (x == 0) return r;
    }
}

}  // namespace v1
}  // namespace sgl
