#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename ForwardIterator1>
/**
 * @brief function equal - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal
*/
// requires(ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1))
bool equal(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1) {
  while (first_0 != last_0) {
    if (*first_0 == *first_1) {} else { return false; }
    ++first_0;
    ++first_1;
  }
  return true;
}
template<typename ForwardIterator0, typename ForwardIterator1>
/**
 * @brief function equal - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal
*/
// requires(ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1))
bool equal(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, ForwardIterator1 last_1, std::input_iterator_tag) {
  while (first_0 != last_0 && first_1 != last_1) {
    if (*first_0 == *first_1) {} else { return false; }
    ++first_0;
    ++first_1;
  }
  return first_0 == last_0 && first_1 == last_1;
}

template<typename RandomAccessIterator0, typename RandomAccessIterator1>
/**
 * @brief function equal - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal
 */
// requires(RandomAccessIterator(RandomAccessIterator0) && RandomAccessIterator(RandomAccessIterator1))
bool equal(RandomAccessIterator0 first_0, RandomAccessIterator0 last_0, RandomAccessIterator1 first_1,
                  RandomAccessIterator1 last_1, std::random_access_iterator_tag) {
  if (last_0 - first_0 < last_1 - last_1) {
    while (first_0 != last_0) {
      if (*first_0 == *first_1) {} else { return false; }
      ++first_0;
      ++first_1;
    }
    return last_1 - first_1 == 0;
  }
  while (first_1 != last_1) {
    if (*first_0 == *first_1) {} else { return false; }
    ++first_0;
    ++first_1;
  }
  return last_0 - first_0 == 0;
}


template<typename ForwardIterator0, typename ForwardIterator1>
/**
 * @brief function equal - compares two ranges of the equal size
 *
 * possible names:
 *  * ranges_equality
 *  * ranges_equal
 *  * range_equals
 *  * equal
*/
// requires(ForwardIterator(ForwardIterator0) && ForwardIterator(ForwardIterator1))
bool equal(ForwardIterator0 first_0, ForwardIterator0 last_0, ForwardIterator1 first_1, ForwardIterator1 last_1) {

#if __cplusplus == 201703L
  if constexpr(std::is_same<typename std::iterator_traits<ForwardIterator0>::iterator_category, std::random_access_iterator_tag>::value &&
               std::is_same<typename std::iterator_traits<ForwardIterator0>::iterator_category, typename std::iterator_traits<ForwardIterator1>::iterator_category>::value) {
    return equal(first_0, last_0, first_1, last_1, std::random_access_iterator_tag{});
  }
  return equal(first_0, last_0, first_1, last_1, std::input_iterator_tag{});
#else
  return equal(first_0, last_0, first_1, last_1, std::input_iterator_tag{});
#endif
}
} // namespace v1
} // namespace sgl
