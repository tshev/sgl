#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct multiply {
    T operator()(const T& x, const T& y) const {
        return x * y;
    }
};

} // namespace v1
} // namespace sgl
