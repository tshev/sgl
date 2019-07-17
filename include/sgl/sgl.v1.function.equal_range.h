#pragma once

namespace sgl {
namespace v1 {
// TODO: can be faster in case of Forward Iterators (std::distance(first, last) is unnecessary we can find middle)

template <typename ForwardIterator, typename T>
std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& val) {
  typedef typename std::iterator_traits<ForwardIterator>::difference_type N;
  N len = std::distance(first, last);

  while (len > 0) {
    N half = len >> 1;
    ForwardIterator middle = first;
    sgl::v1::advance(middle, half);
    if (*middle < val) {
      first = middle;
      ++first;
      len = len - half - 1;
    }
    else if (val < *middle) {
      len = half;
    } else {
      ForwardIterator left = sgl::v1::lower_bound(first, middle, val);
      sgl::v1::advance(first, len);
      ++middle;
      ForwardIterator right = sgl::v1::upper_bound(middle, first, val);
      return {left, right};
    }
  }
  return {first, first};
}

template <typename ForwardIterator, typename T, typename Cmp>
std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& val, Cmp cmp) {
  typedef typename std::iterator_traits<ForwardIterator>::difference_type N;
  N len = std::distance(first, last);

  while (len > 0) {
    N half = len >> 1;
    ForwardIterator middle = first;
    sgl::v1::advance(middle, half);
    if (cmp(*middle, val)) {
      first = middle;
      ++first;
      len = len - half - 1;
    }
    else if (cmp(val, *middle)) {
      len = half;
    } else {
      ForwardIterator left = sgl::v1::lower_bound(first, middle, val, cmp);
      sgl::v1::advance(first, len);
      ++middle;
      ForwardIterator right = sgl::v1::upper_bound(middle, first, val, cmp);
      return {left, right};
    }
  }
  return {first, first};
}

template <typename ForwardIterator, typename T, typename Cmp, typename Projection>
std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& val, Cmp cmp, Projection projection) {
  typedef typename std::iterator_traits<ForwardIterator>::difference_type N;
  N len = std::distance(first, last);

  while (len > 0) {
    N half = len >> 1;
    ForwardIterator middle = first;
    sgl::v1::advance(middle, half);
    if (cmp(projection(*middle), val)) {
      first = middle;
      ++first;
      len = len - half - 1;
    }
    else if (cmp(val, projection(*middle))) {
      len = half;
    } else {
      ForwardIterator left = sgl::v1::lower_bound(first, middle, val, cmp, projection);
      sgl::v1::advance(first, len);
      ++middle;
      ForwardIterator right = sgl::v1::upper_bound(middle, first, val, cmp, projection);
      return {left, right};
    }
  }
  return {first, first};
}


}
} 
