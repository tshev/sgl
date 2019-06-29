#pragma once

#include <iterator>

namespace sgl {
namespace v1 {
template<typename T, typename Transformation>
struct transformation_iterator {
  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef size_t difference_type;

  T value;
  Transformation transformation;

  transformation_iterator() = default;
  transformation_iterator(const transformation_iterator&) = default;
  transformation_iterator(const T& value) : value(value) {}
  transformation_iterator(const T& value, Transformation transformation) : value(value), transformation(transformation) {}
  transformation_iterator(T&& value, Transformation transformation) : value(std::move(value)), transformation(transformation) {}

  transformation_iterator& operator=(const transformation_iterator& x) {
    value = x.value;
    transformation = x.transformation;
    return *this;
  }

  transformation_iterator& operator=(transformation_iterator&& x) {
    value = std::move(x.value);
    transformation = std::move(x.transformation);
    return *this;
  }

  friend
  inline
  bool operator==(const transformation_iterator& x, const transformation_iterator& y) {
    return x.value == y.value;
  }

  friend
  inline
  bool operator!=(const transformation_iterator& x, const transformation_iterator& y) {
    return !(x == y);
  }

  transformation_iterator& operator++() {
    value = transformation(value);
    return *this;
  }

  transformation_iterator operator++(int) {
    transformation_iterator tmp(value, transformation);
    value = transformation(value);
    return tmp;
  }

  value_type& operator*() {
    return value;
  }

  const_reference operator*() const {
    return value;
  }
}; // struct transformation_iterator

template<typename T, typename Transformation>
inline
transformation_iterator<T, Transformation> make_transformation_iterator(const T& value, Transformation transformation) {
  return transformation_iterator<T, Transformation>(value, transformation);
}
} // namespace v1
} // namespace sgl
