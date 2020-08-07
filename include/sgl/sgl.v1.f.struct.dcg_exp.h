#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct dcg_exp {
    T operator()(T relevance, T position_plus_one) const {
        return std::pow(T(2), relevance) / sgl::v1::log2(position_plus_one);
    }
};

}
}
}
