#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename Action, typename N>
N distance_action(T x, T y, Action action, N n) {
    while (x != y) {
        action(x);
        ++n;
    }
    return n;
}

template<typename Action>
DistanceType(Action) distance_action(Domain(Action) x, Domain(Action) y, Action action) {
    typedef DistanceType(Action) N;
    N n(0);

    while (x != y) {
        action(x);
        ++n;
    }

    return n;
}


} // namespace v1
} // namespace sgl
