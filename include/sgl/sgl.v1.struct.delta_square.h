#pragma once
namespace sgl {
namespace v1 {

template<typename T>
struct delta_square {
    T operator()(const T& x, const T& y) const {
        T z = y - x;
        return z * z;
    }
};

}
}
