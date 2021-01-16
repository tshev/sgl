#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct even {
    bool operator()(const T& x) const {
        return x % 2 == 0;
    }
};

} // namespace f
} // namespace v1
} // namespace sgl

