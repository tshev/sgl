#pragma once
#include <memory>
#include <iterator>

namespace sgl {
template<typename Iterator>
struct iterator_traits {
  typedef typename std::iterator_traits<Iterator>::value_type value_type;
};

template<typename T>
struct iterator_traits<std::back_insert_iterator<T>> {
  typedef typename iterator_traits<typename T::iterator>::value_type value_type;
};

struct floating_value_tag {};
struct not_floating_value_tag {};

template<typename T>
struct floating_tag {
  typedef not_floating_value_tag value_type;
};

template<>
struct floating_tag<double> {
  typedef floating_value_tag value_type;
};

template<>
struct floating_tag<long double> {
  typedef floating_value_tag value_type;
};

template<>
struct floating_tag<float> {
  typedef floating_value_tag value_type;
};
} // namespace sgl
