#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename Out>
inline
std::pair<It, Out> move(std::random_access_iterator_tag, It first, size_t n, Out out) {
    return {first + n, sgl::v1::move(first, first + n, out)};
}

template<typename It, typename Out>
inline
std::pair<It, Out> move(std::input_iterator_tag, It first, size_t n, Out out) {
    while (n > 0) {
        *out = std::move(*first);
        ++out;
        ++first;
        --n;
    }
    return {first, out};
}

template<typename It, typename Out>
inline
std::pair<It, Out> move_n(It first, size_t n, Out out) {
    typedef typename std::iterator_traits<It>::iterator_category iterator_category;
    return sgl::v1::move_n(iterator_category{}, first, n, out);
}

} // namespace v1
} // namespace sgl
