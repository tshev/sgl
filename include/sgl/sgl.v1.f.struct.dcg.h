#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct dcg {
    T operator()(T relevance, T position_plus_one) const {
        return relevance / sgl::v1::log2(position_plus_one);
    }
};

}
}
}
