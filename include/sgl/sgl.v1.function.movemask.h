#pragma once

namespace sgl {
namespace v1 {

inline
int movemask(__m128i x) noexcept { return _mm_movemask_epi8(x); }

template<typename T>
inline
auto movemask(const T x) noexcept {
    return movemask(x.value);
}

} // namespace v1
} // namespace sgl
