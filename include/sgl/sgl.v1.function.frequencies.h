#pragma once

namespace sgl {
namespace v1 {

template<typename RandomAccessIterator, typename OutputIteratorputIterator0, typename OutputIteratorputIterator1>
inline
std::pair<OutputIteratorputIterator0, OutputIteratorputIterator1> frequencies(RandomAccessIterator f, RandomAccessIterator l, OutputIteratorputIterator0 out0, OutputIteratorputIterator1 out1, std::random_access_iterator_tag) {
  //typedef size_t N;

  while (f != l) { 
    RandomAccessIterator it = f;
    ++f;
    f = sgl::v1::find_not(f, l, *it);

    *out0 = f - it;
    ++out0;

    *out1 = *it;
    ++out1;
  } 

  return {out0, out1};
}

template<typename It, typename OutputIterator, typename P>
// requires(ForwardIterator(It) && OutputIteratorputIterator(OutputIterator) && Equality(P))
OutputIterator frequencies(It first, It last, OutputIterator out, P p) {
    if (first == last) { return out; }
    auto fast = first;
    ++fast;
    size_t count = 1;
    while (fast != last) {
        if (p(*first, *fast)) {
            count += 1;   
        } else {
          *out = count;
          ++out;
          count = 1;
        }
        ++fast;
        ++first;
    }
    *out = count;
    ++out;
    return out;
}

} // namespace v1
} // namespace sgl
