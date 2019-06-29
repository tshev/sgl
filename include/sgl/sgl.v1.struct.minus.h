#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct minus {
    typedef T value_type;
    T operator()(const T& x, const T& y) {
        return x - y;
    }
};

} // namespace v1
} // namespace sgl
