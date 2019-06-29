#pragma once
namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename ForwardIterator1, typename Transformation>
ForwardIterator1 transform_with_step(ForwardIterator0 f0, ForwardIterator0 l0, size_t step, ForwardIterator1 out, Transformation transformation) {
    while (f0 != l0) {
        *out = transformation(*f0);
        ++out;
        std::advance(f0, step);
    }
    return out;
}

template<typename ForwardIterator0, typename ForwardIterator1, typename Transformation>
ForwardIterator0 transform_with_step(ForwardIterator0 f0, size_t step, ForwardIterator1 f1, ForwardIterator1 l1, Transformation transformation) {
    while (f1 != l1) {
        *f1 = transformation(*f0);
        ++f1;
        std::advance(f0, step);
    }
    return f0;
}
} // namespace v1
} // namespace sgl
