#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct plus {
    typedef T value_type;

    T operator()(const T& x, const T& y) const {
        return x + y;
    }
};

} // namespace f
} // namespace v1
} // namespace sgl
