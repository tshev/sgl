#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct log2 {
    T operator()(const T& value) const {
        return sgl::v1::log2(value);
    }
    
};

}
}
};
