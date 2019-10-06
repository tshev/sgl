#pragma once
namespace sgl {
namespace v1 {

template<typename InputIterator, typename N>
inline
void advance(InputIterator& iterator, N n, std::input_iterator_tag) {
    while (n != 0ul) {
        ++iterator;
        --n;
    }
}

template<typename InputIterator, typename N>
inline
void advance(InputIterator& iterator, N n, std::random_access_iterator_tag) {
    iterator += n;
}

template<typename InputIterator, typename N>
inline
void advance(InputIterator& iterator, N n) {
    typedef typename std::iterator_traits<InputIterator>::iterator_category iterator_tag;
    advance(iterator, n, iterator_tag{});
}

template<typename InputIterator0, typename InputIterator1>
inline
void advance(InputIterator0& first0, InputIterator last0, InputIterator1& first1, std::input_iterator_tag) {
    while (first0 != last0) {
        ++first0;
        ++first1;
    }
}

template<typename RandomAccessIterator0, typename RandomAccessIterator1>
inline
void advance(RandomAccessIterator0& first0, RandomAccessIterator0 last0, RandomAccessIterator1& first1, std::forward_iterator_tag) {
    auto n = last0 - first0;
    first0 += n;
    first1 += n;
}

template<typename InputIterator0, typename InputIterator1>
inline
void advance(InputIterator0& first0, InputIterator last0, InputIterator1& first1) {
    typedef std::iterator_traits<InputIterator0>::iterator_category iterator_category0;
    typedef std::iterator_traits<InputIterator1>::iterator_category iterator_category1;
    if constexpr (std::is_base_of<std::random_access_iterator_tag, iterator_category0>::value && std::is_base_of<std::random_access_iterator_tag, iterator_category1>::value) {
        sgl::v1::advance(first0, last0, first1, std::random_access_iterator_tag());
    } else {
        sgl::v1::advance(first0, last0, first1, std::input_iterator_tag());
    }

}
}  // namespace v1
}  // namespace sgl
