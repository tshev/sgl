#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename ForwardIterator1>
inline
bool contains_all(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1, ForwardIterator1 l1) {
    while (f1 != l1) {
        if (sgl::v1::lower_bound(f0, l0, *f1) == l0) { return false; }
        ++f1;
    }
    return true;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
bool contains_all(ForwardIterator0 f0, ForwardIterator0 l0, BinaryPredicate binary_pred, ForwardIterator1 f1, ForwardIterator1 l1) {
    while (f1 != l1) {
        if (sgl::v1::lower_bound(f0, l0, *f1, binary_pred) == l0) { return false; }
        ++f1;
    }
    return true;
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate, typename Projection>
inline
bool contains_all(ForwardIterator0 f0, ForwardIterator0 l0, BinaryPredicate binary_pred, Projection, ForwardIterator1 f1, ForwardIterator1 l1) {
    while (f1 != l1) {
        if (sgl::v1::lower_bound(f0, l0, *f1, binary_pred) == l0) { return false; }
        ++f1;
    }
    return true;
}



template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate, typename Projection>
inline
ForwardIterator1 inclusion(ForwardIterator0 f0, ForwardIterator0 l0, BinaryPredicate binary_pred, Projection, ForwardIterator1 f1, ForwardIterator1 l1) {
    while (f1 != l1) {
        if (sgl::v1::lower_bound(f0, l0, *f1, binary_pred) == l0) { return f1; }
        ++f1;
    }
    return true;
}

} // namespace v1
} // namespace sgl
