#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct odd {
    bool operator()(const T& x) const {
        return x % 2 != 0;
    }
};

}
}
}
