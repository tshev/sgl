#pragma once

namespace sgl {
namespace v1 {
template<bool x>
struct simd_tag {
    static constexpr const bool aligned = true;
};
} // namespace v1
} // namespace sgl
