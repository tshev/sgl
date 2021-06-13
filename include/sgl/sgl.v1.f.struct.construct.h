#pragma once

namespace sgl {
namespace v1 {
namespace f {

template<typename T>
struct construct {
    template<typename... Args>
    T operator()(Args&&... args) const {
        return T(std::forward<Args>(args)...);
    }
};

} // namespace f
} // namespace v1
} // namespace sgl
