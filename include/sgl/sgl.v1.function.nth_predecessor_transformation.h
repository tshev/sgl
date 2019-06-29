#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename UnaryPredicate, typename Transformation>
inline
T nth_predecessor_transformation(const T& x, UnaryPredicate predicate, Transformation transformation) {
    if (!predicate(x)) { return x; }
    auto slow = x;
    auto fast = action(slow);

    while (predicate(fast)) {
        slow = fast;
        fast = action(slow);
    }
    return slow;
}

} // namespace v1
} // namespace sgl
