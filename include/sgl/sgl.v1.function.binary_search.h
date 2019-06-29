#pragma once

namespace sgl {
namespace v1 {

template<typename RandomAccessIterator, typename T, typename R, typename Projection, typename Eq>
inline
bool binary_search(RandomAccessIterator first, RandomAccessIterator last, const T& value, R r, Projection projection, Eq eq) {
    RandomAccessIterator position = sgl::v1::lower_bound(first, last - first, value, r, projection);
    return position != last && eq(projection(*position), value);
}


template<typename RandomAccessIterator, typename T, typename R, typename Projection>
inline
bool binary_search(RandomAccessIterator first, RandomAccessIterator last, const T& value, R r, Projection projection) {
    RandomAccessIterator position = sgl::v1::lower_bound(first, last - first, value, r, projection);
    return position != last && projection(*position) == value;
}


template<typename RandomAccessIterator, typename T, typename R>
inline
bool binary_search(RandomAccessIterator first, RandomAccessIterator last, const T& value, R r) {
    RandomAccessIterator position = sgl::v1::lower_bound(first, last, value, r);
    return position != last && *position == value;
}


} // namespace v1
} // namespace sgl
