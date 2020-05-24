#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Out, typename N>
inline
Out frequency_pairs(ForwardIterator f, ForwardIterator l, Out out, N zero, std::forward_iterator_tag) {
  while (f != l) { 
    ForwardIterator it = f;
    N n = 1;
    ++f;
    f = sgl::v1::find_not(f, l, *it, n);
    *out = { *it, n };
    ++out;
  } 
  return out;
}


template<typename RandomAccessIterator, typename Out, typename N>
inline
Out frequency_pairs(RandomAccessIterator f, RandomAccessIterator l, Out out, N zero, std::random_access_iterator_tag) {
  while (f != l) { 
    RandomAccessIterator it = f;
    ++f;
    f = sgl::v1::find_not(f, l, *it);
    *out = { *it, N(f - it) };
    ++out;
  } 
  return out;
}


template<typename RandomAccessIterator, typename OutputIterator0, typename OutputIterator1>
inline
std::pair<OutputIterator0, OutputIterator1> frequency_pairs(RandomAccessIterator f, RandomAccessIterator l, OutputIterator0 out0, OutputIterator1 out1, std::random_access_iterator_tag) {
  while (f != l) { 
    RandomAccessIterator it = f;
    ++f;
    f = sgl::v1::find_not(f, l, *it);

    *out0 = *it;
    ++out0;

    *out1 = f - it;
    ++out1;
  } 

  return {out0, out1};
}

template<typename It, typename Out, typename P>
// requires(ForwardIterator(It) && OutputIterator(Out) && Equality(P))
Out frequency_pairs(It first, It last, Out out, P p) {
    if (first == last) { return out; }
    auto fast = first;
    ++fast;
    size_t count = 1;
    while (fast != last) {
        if (p(*first, *fast)) {
            count += 1;   
        } else {
          *out = {*first, count};
          ++out;
          count = 1;
        }
        ++fast;
        ++first;
    }
    *out = {*first, count};
    ++out;
    return out;
}

/*
template<typename ForwardIterator, typename Out>
Out frequency_pairs(ForwardIterator f, ForwardIterator l, Out out) {
  typedef SGLValueType(ForwardIterator) T;

  if (f == l) return out;
  *out = { *f, 1 };
  ForwardIterator step_back = f;
  ++f;
  size_t count = 1;
  while (f != l) { 
    if (*step_back == *f) {
      ++count;
    } else {
      *out = { *step_back, count };
      count = 1;
      ++out;
    }
    ++f;
    ++step_back;
  } 
  *out = { *step_back, count };
  ++out;
  return out;
}
*/

} // namespace v1
} // namespace sgl
