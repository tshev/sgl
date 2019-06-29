#pragma once

namespace sgl {
namespace v1 {
namespace reducer {

template<typename T>
struct square_deviation {
    T value;

    square_deviation() = default;
    square_deviation(T x) : value(x) {}
    square_deviation(const square_deviation&) = default;
    ~square_deviation() = default;

    T operator()(const T& r, const T& x) const {
        T y = (x - value);
        return r + y * y;
    }
};

} // namespace reducer
} // namespace v1
} // namespace sgl
