#pragma once
namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename T>
inline
void uninitialized_copy_construct(ForwardIterator first, ForwardIterator last, const T& x) {
    if constexpr (std::is_nothrow_copy_constructible<typename std::iterator_traits<ForwardIterator>::value_type>::value) {
        while (first != last) {
            sgl::v1::uninitialized_construct(*first, x);
            ++first;
        }
    } else {
        ForwardIterator start = first;
        try {
            while (first != last) {
                sgl::v1::uninitialized_construct(*first, x);
                ++first;
            }
        } catch(...) {
             sgl::v1::destruct(start, first);
             throw;
        }
    }
}
} // namespace v1
} // namespace sgl
