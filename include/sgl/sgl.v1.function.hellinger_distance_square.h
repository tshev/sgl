#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1, typename T>
T hellinger_distance_square(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, T result) {
    while (f0 != l0) {
        result += sgl::v1::square(sgl::v1::sqrt(*f0) - sgl::v1::sqrt(*f1));
    }
    return result / T(2.0);
}

template<typename ForwardIterator0, typename ForwardIterator1, typename T, typename Projection0>
T hellinger_distance_square(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, T result, Projection0 p0) {
    while (f0 != l0) {
        result += sgl::v1::square(sgl::v1::sqrt(p0(*f0)) - sgl::v1::sqrt(*f1));
    }
    return result / T(2.0);
}

template<typename ForwardIterator0, typename ForwardIterator1, typename T, typename Projection0, typename Projection1>
T hellinger_distance_square(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, T result, Projection0 p0, Projection1 p1) {
    while (f0 != l0) {
        result += sgl::v1::square(sgl::v1::sqrt(p0(*f0)) - sgl::v1::sqrt(p1(*f1)));
        // sqrt_diff_square_sum
    }
    return result / T(2.0);
}

} // namespace v1
} // namespace sgl
