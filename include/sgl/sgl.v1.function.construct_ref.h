#pragma once

namespace sgl {
namespace v1 {
template<typename T>
inline
T& construct_ref(T* x) {
    return *(new (x) T());
}
} // namespace v1
} // namespace sgl
