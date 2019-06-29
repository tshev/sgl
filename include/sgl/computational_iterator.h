#pragma once

namespace sgl {

template<typename T, typename Transformation>
struct computational_iterator {
  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef size_t difference_type;


  T* value;
  Transformation transformation;

  computational_iterator() = default;
  computational_iterator(T* value, Transformation transformation) : value(value), transformation(transformation) {}
  computational_iterator(T &value, Transformation transformation) : value(&value), transformation(transformation) {}
  computational_iterator(const computational_iterator&) = default;

  computational_iterator& operator=(const computational_iterator& x) {
    value = x.value;
    transformation = x.transformation;
    return *this;
  }

  computational_iterator& operator++() {
    *value = transformation(*value);
    return *this;
  }

  T& operator*() {
    return *value;
  }

  const T& operator*() const {
    return *value;
  }
}; // struct computational_iterator

template <typename T, typename Transformation>
inline
computational_iterator<T, Transformation> make_computational_iterator(T& value, Transformation transformation) {
  return transformation_iterator<T, Transformation>(&value, transformation);
}
} // namespace sgl
