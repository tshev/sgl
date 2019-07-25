#pragma once
namespace sgl {
namespace v1 {

template<typename It0, typename It1, typename F>
// requires(ForawrdIterator(It0) && ForawrdIterator(It1) && BinaryFunction(F))
inline
std::pair<It0, It1> zip_position(It0 f0, It0 l0, It1 f1, It1 l1, F f, std::input_iterator_tag) {
    while (f0 != l0 && f1 != l1) {
        f(f0, f1);
        ++f0;
        ++f1;
    }
    return {f0, f1};
}

template<typename It0, typename It1, typename F>
// requires(RandomAccessIterator(It0) && RandomAccessIterator(It1) && BinaryFunction(F))
inline
std::pair<It0, It1> zip_position(It0 f0, It0 l0, It1 f1, It1 l1, F f, std::random_access_iterator_tag) {
    if (l1 - f1 < l0 - f0) {
        while (f1 != l1) {
            f(f0, f1);
            ++f0;
            ++f1;
        }
    } else {
        while (f0 != l0) {
            f(f0, f1);
            ++f0;
            ++f1;
        }
    }
    return {f0, f1};
}

template<typename It0, typename It1, typename F>
//requires(ForawrdIterator(It0) && ForawrdIterator(It1) && BinaryFunction(F))
inline
std::pair<It0, It1> zip_position(It0 f0, It0 l0, It1 f1, It1 l1, F f) {
    typedef typename std::iterator_category<It0>::iterator_category iterator_category0;
    typedef typename std::iterator_category<It1>::iterator_category iterator_category1;

    constexpr bool enable_forward_iterator =
        std::is_same<iterator_category0, std::random_access_iterator_tag>::value &&
        std::is_same<iterator_category1, std::random_access_iterator_tag>::value;
    typedef typename sgl::v1::if_else<enable_forward_iterator, std::input_iterator_tag, std::random_access_iterator_tag>::type;

    return zip_position(f0, l0, f1, l1, f, iterator_category{});
}

} // namespace v1
} // namespace sgl
