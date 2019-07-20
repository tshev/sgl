#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
inline
std::pair<It0, It1> swap_ranges(It0 first0, It0 last0, It1 first1, It1 last1, std::forward_iterator_tag) {
    using std::swap;
    while (first0 != last0 && first1 != last1) {
        swap(*first0, *first1);
        ++first0;
        ++first1;
    }
    return {first0, first1};
}

template<typename It0, typename It1>
inline
std::pair<It0, It1> swap_ranges(It0 first0, It0 last0, It1 first1, It1 last1, std::random_access_iterator_tag) {
    using std::swap;
    if (last1 - first1 < last0 - first0) {
        while (first1 != last1) {
            std::swap(*first0, *first1);
            ++first0;
            ++first1;
        }
    } else {
        while (first0 != last0) {
            swap(*first0, *first1);
            ++first0;
            ++first1;
        }
    }
    return {first0, first1};
}

template<typename It0, typename It1>
inline
std::pair<It0, It1> swap_ranges(It0 first0, It0 last0, It1 first1, It1 last1) {
    typedef typename std::iterator_traits<It0>::iterator_category iterator_category0;
    typedef typename std::iterator_traits<It1>::iterator_category iterator_category1;
    if constexpr (std::is_same<iterator_category0, iterator_category1>::value) {
        return sgl::v1::swap_ranges(first0, last0, first1, last1, iterator_category0{});
    } else {
        return sgl::v1::swap_ranges(first0, last0, first1, last1, std::forward_iterator_tag{}); 
    }
}
} // namespace v1
} // namespace sgl
