#pragma once

namespace sgl {
namespace v1 {

template<typename It>
requires(sgl::v1::forward_iterator<It>)
inline
auto distance(It first, It last, std::forward_iterator_tag) {
    typedef typename std::iterator_traits<It>::difference_type D;
    D d = 0;
    while (first != last) {
        ++first;
        ++d;
    }
    return d;
}

template<typename It>
inline
auto distance(It first, It last, std::random_access_iterator_tag) {
    typedef typename std::iterator_traits<It>::difference_type D;
    return D(last - first);
}

template<typename It>
inline
requires(sgl::v1::forward_iterator<It>)
auto distance(It first, It last) {
    typedef typename std::iterator_traits<It>::iterator_category tag_type;
    return sgl::v1::distance(first, last, tag_type{});
}

} // namespace v1
} // namespace sgl
