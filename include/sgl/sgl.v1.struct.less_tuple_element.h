#pragma once

namespace sgl {
namespace v1 {

template<size_t I>
struct less_tuple_element {
    template<typename T>
    bool operator()(const T& x, const T& y) const {
        return std::get<I>(x) < std::get<I>(y);
    }
};

}
}
