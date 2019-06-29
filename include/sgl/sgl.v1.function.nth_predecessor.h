#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
// requires(Regular(T))
inline
ForwardIterator nth_predecessor(ForwardIterator first, ForwardIterator last, T n) {
    if (n == 0) { return last; }
    return sgl::v1::nth_predecessor_unguarded(first, last, n);
}

} // namespace v1
} // namespace sgl
