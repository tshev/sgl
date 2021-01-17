#pragma once
namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct max {
    const T& operator()(const T& x, const T& y) const {
        return sgl::v1::max(x, y);
    }

    T& operator()(T& x, T& y) const {
        return sgl::v1::max(x, y);
    }
};

} // namespace f
} // namespace v1
} // namespace sgl
