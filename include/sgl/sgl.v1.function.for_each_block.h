#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename N, typename Function>
inline
void for_each_block(ForwardIterator0 first, N n, N max_block_size, Function function) {
    // TODO: optimize for random access iterators
    typedef size_t size_type;
    size_type n_blocks = n / max_block_size;
    for (size_type i = 0; i != n_blocks; i += max_block_size) {
        ForwardIterator0 next = std::next(first, max_block_size);
        function(first, next);
        first = next;
    }
    ForwardIterator0 last = first + n;
    if (first != last) {
        function(first, last);
    }
}


template<typename ForwardIterator0, typename N, typename Function>
void for_each_block(ForwardIterator0 first, ForwardIterator0 last, N max_block_size, Function function) {
    // TODO: optimize for random access iterators
    typedef size_t size_type;
    size_type n = std::distance(first, last);
    size_type n_blocks = n / max_block_size;
    for (size_type i = 0; i != n_blocks; i += max_block_size) {
        ForwardIterator0 next = std::next(first, max_block_size);
        function(first, next);
        first = next;
    }
    if (first != last) {
        function(first, last);
    }
}


template<typename ForwardIterator0, typename Function>
inline
void for_each_block(ForwardIterator0 first, ForwardIterator0 middle, ForwardIterator0 last, Function function) {
    size_t max_block_size = std::distance(first, middle);
    return sgl::v1::for_each_block(first, middle, max_block_size, function);
}

} // namespace v1
} // namespace sgl
