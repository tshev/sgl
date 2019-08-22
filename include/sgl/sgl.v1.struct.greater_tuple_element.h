#pragma once

namespace sgl {
namespace v1 {

template<size_t I>
struct greater_tuple_element {
    template<typename T>
    bool operator()(const T& x, const T& y) const {
        return std::get<I>(y) < std::get<I>(x);
    }
};

}
}
