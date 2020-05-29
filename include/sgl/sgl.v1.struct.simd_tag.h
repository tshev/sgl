#pragma once

namespace sgl {
namespace v1 {


template<bool x, typename T>
struct simd_tag {
    typedef typename T::block_type block_type;
    static constexpr const bool aligned = x;
};

} // namespace v1
} // namespace sgl
