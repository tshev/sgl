namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename ForwardIterator1>
/**
 * @brief function equal_ranges - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal_ranges
*/
// requires(ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1))
std::pair<ForwardIterator0, ForwardIterator1> equal_ranges(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1) {
  while (first0 != last0) {
    if (*first0 == *first1) {} else { return {first0, first1}; }
    ++first0;
    ++first1;
  }
  return {first0, first1};
}
template<typename ForwardIterator0, typename ForwardIterator1>
/**
 * @brief function equal_ranges - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal_ranges
*/
// requires(ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1))
std::pair<ForwardIterator0, ForwardIterator1> equal_ranges(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1, std::input_iterator_tag) {
  while (first0 != last0 && first1 != last1) {
    if (*first0 == *first1) {} else { return {first0, first1}; }
    ++first0;
    ++first1;
  }
  return {first0, first1};
}

template<typename RandomAccessIterator0, typename RandomAccessIterator1>
/**
 * @brief function equal_ranges - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal_ranges
 */
// requires(RandomAccessIterator(RandomAccessIterator0) && RandomAccessIterator(RandomAccessIterator1))
std::pair<RandomAccessIterator0, RandomAccessIterator1> equal_ranges(RandomAccessIterator0 first0, RandomAccessIterator0 last0, RandomAccessIterator1 first1,
                  RandomAccessIterator1 last1, std::random_access_iterator_tag) {
  if (last0 - first0 < last1 - last1) {
    while (first0 != last0) {
      if (*first0 == *first1) {} else { return {first0, first1}; }
      ++first0;
      ++first1;
    }
    return {first0, first1};
  }
  while (first1 != last1) {
    if (*first0 == *first1) {} else { return {first0, first1}; }
    ++first0;
    ++first1;
  }
  return {first0, first1};
}


template<typename ForwardIterator0, typename ForwardIterator1>
/**
 * @brief function equal_ranges - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal_ranges
*/
// requires(ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1))
std::pair<ForwardIterator0, ForwardIterator1> equal_ranges(ForwardIterator0 first0, ForwardIterator0 last0, ForwardIterator1 first1, ForwardIterator1 last1) {

#if __cplusplus == 201703L
  if constexpr(std::is_same<typename std::iterator_traits<ForwardIterator0>::iterator_category, std::random_access_iterator_tag>::value &&
               std::is_same<typename std::iterator_traits<ForwardIterator0>::iterator_category, typename std::iterator_traits<ForwardIterator1>::iterator_category>::value) {
    return equal_ranges(first0, last0, first1, last1, std::random_access_iterator_tag{});
  }
  return equal_ranges(first0, last0, first1, last1, std::input_iterator_tag{});
#else
  return equal_ranges(first0, last0, first1, last1, std::input_iterator_tag{});
#endif
}
} // namespace v1
} // namespace sgl
