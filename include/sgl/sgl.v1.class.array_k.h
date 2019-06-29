#pragma once
#include <vector>
#include "algorithm.h"

namespace sgl {
namespace v1 {
struct copy_string_predicate {
  size_t n;
  size_t i = 0;
  copy_string_predicate(size_t n) : n(n), i(0) {}
  bool operator()(char sym) {
    return i++ != n && sym != '\0';
  }
};


template<typename T, size_t K>
class array_k : totally_ordered<array_k<T, K> >{
public:
  typedef T value_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef void allocator_type;

  typedef T* iterator;
  typedef const T* const_iterator;

  typedef T* pointer;
  typedef const T* const_pointer;

  typedef const T& const_reference;
  
  struct reverse_iterator {
    pointer data_;

    reverse_iterator(const_pointer data) : data_(data) {}

    reverse_iterator(const reverse_iterator&) = default;

    reverse_iterator& operator=(const reverse_iterator &x) {
      data_ = x.data_;
      return *this;
    }

    friend
    inline
    bool operator==(reverse_iterator x, reverse_iterator y) {
      return x.data_ == y.data_;
    }

    friend
    inline
    bool operator!=(reverse_iterator x, reverse_iterator y) {
      return x.data_ != y.data_;
    }

    reverse_iterator operator++(int) {
      auto tmp = *this;
      --data_;
      return tmp;
    }

    reverse_iterator& operator++() {
      --data_;
      return *this;
    }

    reverse_iterator operator--(int) {
      auto tmp = *this;
      ++data_;
      return tmp;
    }

    reverse_iterator& operator--() {
      ++data_;
      return *this;
    }

    T& operator*() {
      return *data_;
    }

    const T& operator*() const {
      return *data_;
    }
  };

  typedef const reverse_iterator const_reverse_iterator;

private:
  T data_[K];

public:
  explicit constexpr array_k() = default;

  array_k(const std::initializer_list<T> &x) {
    std::copy(std::begin(x), std::end(x), data_);
  }

  constexpr array_k(size_type n, const T &value) {
    std::fill_n(data_, n, value);
  }

  constexpr array_k(const array_k& x) {
    std::copy(x.begin(), x.end(), begin());
  }

  template<typename U>
  array_k(const U &x) {
    std::copy(std::begin(x), std::end(x), data_);
  }

  array_k(const char *x) {
    sgl::v1::copy_while(x, data_, [](auto x) { return x != '\0'; });
  }

  constexpr array_k& operator=(const array_k& x) {
    std::copy(x.begin(), x.end(), begin());
    return *this;
  }

  template<typename U>
  constexpr array_k& operator=(const U& x) {
    std::copy(std::begin(x), std::end(x), data_);
    return *this;
  }

  friend
  inline
  bool operator==(const array_k &x, const array_k &y) {
    return sgl::v1::equal_ranges(std::begin(x), std::end(x), std::begin(y));
  }

  friend
  inline
  bool operator!=(const array_k &x, const array_k &y) {
    return !(x == y);
  }

  value_type& operator[](size_type i) {
    return data_[i];
  }

  const value_type& operator[](size_type i) const {
    return data_[i];
  }

  iterator begin() {
    return data_ ;
  }

  const_iterator begin() const {
    return data_;
  }

  iterator end() {
    return data_ + size();
  }

  const_iterator end() const {
    return data_ + size();
  }

  reverse_iterator rbegin() {
    return reverse_iterator(data_ + size() - 1ul);
  }

  const_reverse_iterator rbegin() const {
    return reverse_iterator(data_ + size() - 1ul);
  }

  reverse_iterator rend() {
    return reverse_iterator(data_ - 1ul);
  }

  const_iterator rend() const {
    return reverse_iterator(data_ - 1ul);
  }

  constexpr size_type size() const {
    return K;
  }

  size_type capacity() const {
    return K;
  }

  value_type& front() {
    return data_[0];
  }

  const value_type& front() const {
    return data_[0];
  }

  value_type& back() {
    return data_[size() - 1ul];
  }

  const value_type& back() const {
    return data_[size() - 1ul];
  }


  friend
  inline
  bool operator<(const array_k& x, const array_k& y) {
    return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }
};
} // namespace v1
} // namespace sgl
