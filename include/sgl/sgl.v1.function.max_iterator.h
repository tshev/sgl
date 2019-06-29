#pragma once

namespace sgl {
namespace v1 {

template<typename Iterator>
// requires(StrictWeakOrdering(Iterator::operator<))
inline
const Iterator& max_iterator(const Iterator &x, const Iterator &y) {
  if (!(y < x)) {
    return y;
  } else {
    return x;
  }
}

template <typename Iterator>
// requires(StrictWeakOrdering(Iterator::operator<))
inline
Iterator& max_iterator(Iterator& x, Iterator& y) {
    if (!(y < x)) {
        return y;
    } else {
        return x;
    }
}


template <typename Iterator, typename P>
// requires(StrictWeakOrdering(P, Iterator))
inline
const Iterator& max_iterator(const Iterator& x, const Iterator& y, P p) {
    if (!p(*y, *x)) {
        return y;
    } else {
        return x;
    }
}

template <typename Iterator, typename P>
// requires(StrictWeakOrdering(P, Iterator))
inline
Iterator& max_iterator(Iterator& x, Iterator& y, P p) {
    if (!p(*y, *x)) {
        return y;
    } else {
        return x;
    }
}

} // namespace v1
} // namespace sgl
