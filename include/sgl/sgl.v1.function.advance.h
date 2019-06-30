#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator>
inline
void advance(InputIterator& iterator, size_t n, std::input_iterator_tag) {
    while (n != 0ul) {
        ++iterator;
        --n;
    }
}

template<typename InputIterator>
inline
void advance(InputIterator& iterator, size_t n, std::random_access_iterator_tag) {
    iterator += n;
}

template<typename InputIterator>
inline
void advance(InputIterator& iterator, size_t n) {
    typedef typename std::iterator_traits<InputIterator>::iterator_category iterator_tag;
    advance(iterator, n, iterator_tag{});
}


}
}
