#pragma once

#include "macros.h"
#include "common.h"
#include <sstream>
#include <cassert>
#include <random>
#include <chrono>
#include <iostream>
#include <cassert>
#include <cmath>
#include <type_traits>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#include <tuple>

#include <exception>
#include <cstring>
#include <iterator>

extern "C" {
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
}
#include "sgl.v1.h"

/************************************ Concepts START *********************************/
namespace sgl {
namespace v1 {
template <typename Key, typename Allocator = std::allocator<Key>>
using set_max = std::set<Key, std::greater<Key>, Allocator>;


namespace tag {
  struct success {
    const char* name = "success";
  };

  struct failure {
    const char* name = "failure";
  };

  struct running {
    const char* name = "running";
  };
} // end of namespace tag




template<typename It, typename ThreeWayCmp>
It merge_unique_inplace_3way(It f, It m, It l, ThreeWayCmp cmp) {
  auto out = f;
  auto middle = m;

  while (f != middle && m != l) {
    auto comparison = cmp(*f, *m);
    if (comparison < 0) {
      *out = std::move(*f);
      f = find_not(f, middle, *out);
    } else if (comparison > 0) {
      *out = std::move(*m);
      m = find_not(m, l, *out);
    } else {
      *out = std::move(*m);
      f = find_not(f, middle, *out);
      m = find_not(m, l, *out);
    }
    ++out;
  }

  while (f != middle) {
    *out = std::move(*f);
    f = find_not(f, middle, *out);
    ++out;
  }

  while (m != l) {
    *out = std::move(*m);
    m = find_not(m, l, *out);
    ++out;
  }

  return out;
}


template<typename It>
It merge_unique_inplace(It f, It m, It l) {
  auto out = f;
  auto middle = m;

  while (f != middle && m != l) {
    if (*f < *m) {
      *out = std::move(*f);
      f = find_not(f, middle, *out);
    } else if (*f > *m) {
      *out = std::move(*m);
      m = find_not(m, l, *out);
    } else {
      *out = std::move(*m);
      f = find_not(f, middle, *out);
      m = find_not(m, l, *out);
    }
    ++out;
  }

  while (f != middle) {
    *out = std::move(*f);
    f = find_not(f, middle, *out);
    ++out;
  }

  while (m != l) {
    *out = std::move(*m);
    m = find_not(m, l, *out);
    ++out;
  }

  return out;
}



namespace functor {
  template<typename Predicate>
  struct min_op {
    Predicate cmp;
    min_op(Predicate cmp) : cmp(cmp) {}

    template<typename Iterator>
    Iterator operator()(Iterator x, Iterator y) {
      if (cmp(*y, *x)) {
        return y;
      } else {
        return x;
      }
    }
  };
}

template<typename ForwardIterator, typename Out, typename Predicate>
Out interval_frequency_pairs_bs(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) width, Out out, Predicate pred, floating_value_tag _) {
  typedef SGLValueType(Out) pair_type;
  typedef SGLSecondType(pair_type) N;
  typedef SGLFirstType(pair_type) T;
  if (f == l) return out; 
  const auto val = *f;
  size_t pos = 1;
  while (f != l) {
    T current_val = *val + pos * width;
    auto it_pos = std::lower_bound(f, l, current_val, pred);
    *out = {*f, N(pos - f) };
    f = it_pos;
    ++pos;
    ++out;
  }
  return out;
}


template<typename It, typename Out, typename Predicate>
Out frequency_interval_pairs_bs(It f, It l, SGLValueType(It) width, Out out, Predicate pred, not_floating_value_tag _) {
  typedef SGLValueType(Out) pair_type;
  typedef SecondType(pair_type) N;

  if (f == l) return out;
  auto val = *f;
  while (true) {
    auto pos = std::lower_bound(f, l, val, pred);
    *out = {*f, N(pos - f) };
    ++out;
    if (pos == l) return out;
    val += width;
    f = pos;
  }
  return out;
}

template<typename ForwardIterator, typename Out, typename Predicate>
inline
Out interval_frequency_pairs_bs(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) width, Out out, Predicate pred) {
  typedef typename floating_tag<SGLValueType(ForwardIterator)>::value_type tag_type;
  return interval_frequency_pairs_bs(f, l, width, out, pred, tag_type{});
}

template<typename It, typename Out, typename Predicate>
// TODO think about projection instead of wring new version (It looks like a predicate which always returns true)
Out frequency_intervals_bs(It f, It l, SGLValueType(It) width, Out out, Predicate pred, floating_value_tag _) {
  typedef SGLValueType(Out) N;
  //typedef SGLValueType(It) T;
  const auto f_const = f;
  size_t i = 1;
  while (true) {
    auto val = *f_const  + i * width;
    It pos = std::upper_bound(f, l, val, pred);
    *out = N(pos - f);
    ++out;
    if (pos == l) return out;
    f = pos;
    val += width;
    ++i;
  }
  return out;
}

template<typename It, typename Out, typename Predicate>
// TODO think about projection instead of wring new version (It looks like a predicate which always returns true)
Out frequency_intervals_bs(It f, It l, SGLValueType(It) width, Out out, Predicate pred, not_floating_value_tag _) {
  // [ ] (], ..., (], (]
  typedef SGLValueType(Out) N;
  typedef SGLValueType(It) T;

  if (f == l) return out;
  T val = *f;
  while (true) {
    It pos = std::lower_bound(f, l, val, pred);
    if (pos == l) return out;
    val += width;
    *out = N(pos - f);
    f = pos;
    ++out;
  }
  return out;
}

template<typename ForwardIterator, typename Out, typename Predicate>
inline
Out frequency_intervals_bs(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) width, Out out, Predicate pred) {
  typedef typename floating_tag<SGLValueType(ForwardIterator)>::value_type tag_type;
  return frequency_intervals_bs(f, l, width, out, pred, tag_type{});
}

template<typename ForwardIterator>
SGLValueType(ForwardIterator) mode(ForwardIterator f, ForwardIterator l, SGLValueType(ForwardIterator) width) {
  //std::nth_element(f, f + (l - f)/2, l, [](auto x, auto y) {});
  typedef SGLValueType(ForwardIterator) T;
  auto &left = *f;
  auto &right = *(l - 1);
  auto n = std::ceil(right - left) / width;
  std::vector<T> ranges; // fix

  const T &x_m_0 = *f;
  auto h_m_0 = std::distance(f, l);
}



template<typename RandomAccessIterator, typename OutputIteratorFrequncies>
// requires(is_sorted(f, l) && RandomAccessIterator(RandomAccessIterator) && OutputIterator(OutputIterator)
OutputIteratorFrequncies
frequencies_only_bs(RandomAccessIterator f, RandomAccessIterator l, OutputIteratorFrequncies out_freq) {
  typedef SGLValueType(OutputIteratorFrequncies) N;
  while (f != l) { 
    RandomAccessIterator step_back = f; 
    f = std::upper_bound(f + 1, l, *step_back);
    *out_freq = N(f - step_back);
    ++out_freq;
  } 
  return out_freq;
}


//template<typename T>
//using increment_iterator = transformation_iterator<T, increment<T>>;
} // namespace v1
} // namespace sgl

//namespace st = sgl::transformation;
//namespace sa = sgl::action;
