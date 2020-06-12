#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct multiply {
    T operator()(const T& x, const T& y) const {
        return x * y;
    }
};

} // namespace f
} // namespace v1
} // namespace sgl
