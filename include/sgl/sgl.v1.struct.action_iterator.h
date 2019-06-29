#pragma once
#include <iterator>

namespace sgl {
namespace v1 {
template<typename T, typename Action>
struct action_iterator {
  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef size_t difference_type;

  T value;
  Action action;

  action_iterator() = default;
  action_iterator(const action_iterator&) = default;
  action_iterator(const T& value) : value(value) {}
  action_iterator(T&& value) : value(std::move(value)) {}
  action_iterator(const T& value, Action action) : value(value), action(std::move(action)) {} // Not sure about move
  action_iterator(T&& value, Action action) : value(std::move(value)), action(action) {} // Not sure about move

  action_iterator& operator=(const action_iterator& x) {
    value = x.value;
    action = x.action;
    return *this;
  }

  action_iterator& operator=(action_iterator&& x) {
    value = std::move(x.value);
    action = std::move(x.action);
    return *this;
  }

  friend
  inline
  bool operator==(const action_iterator& x, const action_iterator& y) {
    return x.value == y.value;
  }

  friend
  inline
  bool operator!=(const action_iterator& x, const action_iterator& y) {
    return !(x == y);
  }

  action_iterator& operator++() {
    action(value);
    return *this;
  }

  action_iterator operator++(int) {
    action_iterator tmp(value, action);
    action(value);
    return tmp;
  }

  value_type& operator*() {
    return value;
  }

  const_reference operator*() const {
    return value;
  }
}; // struct action_iterator

template<typename T, typename Action>
inline
sgl::action_iterator<T, Action> make_action_iterator(const T& value, Action action) {
  return sgl::action_iterator<T, Action>(value, std::move(action));
}
} // namespace v1
} // namespace sgl
