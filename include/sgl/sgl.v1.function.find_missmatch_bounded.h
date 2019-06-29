#pragma once

namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename ForwardIterator1>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch_bounded(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, std::forward_iterator_tag) {
  while (first0 != last0 && first1 != last1) {
    if (*first0 != *first1) { return {first0, first1}; }
    ++first0;
    ++first1;
  }
  return {first0, first1};
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch_bounded(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, BinaryPredicate pred, std::forward_iterator_tag) {
  while (first0 != last0 && first1 != last1) {
    if (!pred(*first0, *first1)) { return {first0, first1}; }
    ++first0;
    ++first1;
  }
  return {first0, first1};
}


template<typename ForwardIterator0, typename ForwardIterator1>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch_bounded(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, std::random_access_iterator_tag) {
    if (last0 - first0 < last1 - first1) {
        return sgl::v1::find_missmatch(first0, last0, first1);
    }
    auto result = sgl::v1::find_missmatch(first1, last1, first0);
    return std::make_pair(result.second, result.first);
}


template<typename ForwardIterator0, typename ForwardIterator1>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch_bounded(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1) {
    typedef typename std::iterator_traits<ForwardIterator0>::iterator_category iterator_category0;
    typedef typename std::iterator_traits<ForwardIterator1>::iterator_category iterator_category1;

    constexpr bool precondition = std::is_same<iterator_category0, iterator_category1>::value && std::is_same<iterator_category0, std::random_access_iterator_tag>::value;
    typedef typename if_else<precondition, std::random_access_iterator_tag, std::forward_iterator_tag>::value_type iterator_category;

    return sgl::v1::find_missmatch_bounded(first0, last0, first1, last1, iterator_category{});
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch_bounded(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, BinaryPredicate pred, std::random_access_iterator_tag) {
    if (last0 - first0 < last1 - first1) {
        return sgl::v1::find_missmatch(first0, last0, last1, pred);
    }
    auto result = sgl::v1::find_missmatch(first1, last1, last1, pred);
    return {result.second, result.first};
}


template<typename ForwardIterator0, typename ForwardIterator1, typename BinaryPredicate>
inline
std::pair<ForwardIterator0, ForwardIterator1> find_missmatch_bounded(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, BinaryPredicate pred) {
    typedef typename std::iterator_traits<ForwardIterator0>::iterator_category iterator_category0;
    typedef typename std::iterator_traits<ForwardIterator1>::iterator_category iterator_category1;

    constexpr bool precondition = std::is_same<iterator_category0, iterator_category1>::value && std::is_same<iterator_category0, std::random_access_iterator_tag>::value;
    typedef typename if_else<precondition, std::random_access_iterator_tag, std::forward_iterator_tag>::value_type iterator_category;

    return sgl::v1::find_missmatch_bounded(first0, last0, first1, last1, pred, iterator_category{});
}

} // namespace sgl
} // namespace 
