#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename ForwardIterator>
ForwardIterator uninitialized_copy_trivial(InputIterator first, InputIterator last, ForwardIterator out) {
    ForwardIterator current = out;
    try {
        for (; first != last; ++current, ++first) {
            sgl::v1::uninitialized_construct(std::addressof(*current), *first);
        }
        return current;
    } catch (...) {
        sgl::v1::destruct(current, current);
        throw;
    }
}

} // namespace v1
} // namespace sgl
