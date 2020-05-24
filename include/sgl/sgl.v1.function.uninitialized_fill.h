#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
requires(sgl::v1::forward_iterator(ForwardIterator) && sgl::v1::readable(ForwardIterator))
void uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& value) {
    if constexpr (std::is_nothrow_copy_constructible<T>::value) {
        while (first != last) {
            sgl::v1::uninitialized_copy_construct(*first, value);
            ++first;
        }
    } else {
        auto first_fixed = first;
        try {
            while (first != last) {
                sgl::v1::uninitialized_copy_construct(*first, value);
                ++first;
            }
        } catch (...) {
            sgl::v1::destruct(first_fixed, first);
        }
    }
}

} // namespace v1
} // namespace sgl
