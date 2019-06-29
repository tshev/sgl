#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename Transformation, typename N>
N distance_transformation(T x, T y, Transformation f, N n) {
    while (x != y) {
        x = f(x);
        ++n;
    }
    return n;
}

template<typename Transformation>
DistanceType(Transformation) distance_transformation(Domain(Transformation) x, Domain(Transformation) y, Transformation f) {
    typedef DistanceType(Transformation) N;
    N n(0);

    while (x != y) {
        x = f(x);
        ++n;
    }

    return n;
}


} // namespace v1
} // namespace sgl
