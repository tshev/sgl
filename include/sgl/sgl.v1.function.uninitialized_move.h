#pragma once

namespace sgl {
namespace v1 {

template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator output) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    ForwardIterator current = output;
    try {
        while (first != last) {
            ::new (static_cast<void*>(std::addressof(*current))) value_type(std::move(*first));
            ++first;
            ++current;
        }
        return current;
    } catch (...) {
        while (output != current) {
            output->~value_type();
            ++output;
        }
        throw;
    }
}

} // namespace v1
} // namespace sgl
