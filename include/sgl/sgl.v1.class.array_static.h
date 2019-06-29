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


template<typename T, size_t N>
class array_static : totally_ordered<array_static<T, N> >{
public:
  typedef T value_type;
  typedef size_t size_type;
  typedef size_type difference_type;
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
  T data_[N];
  size_type size_;

public:
  explicit constexpr array_static() : size_(0u) { }

  explicit constexpr array_static(size_type n) : size_(n) {}
  explicit constexpr array_static(int n) : size_(static_cast<size_type>(n)) {}

  array_static(const std::initializer_list<T> &x) : size_(x.size()) {
    std::copy(std::begin(x), std::end(x), data_);
  }

  constexpr array_static(size_type n, const T &value) : size_(n) {
    std::fill_n(data_, size_, value);
  }

  constexpr array_static(const array_static& x) : size_(x.size_) {
    std::copy(x.data_, x.data_ + x.size_, data_);
  }

  template<typename U>
  array_static(const U &x) : size_(x.size_){
    std::copy(std::begin(x), std::end(x), data_);
  }

  array_static(const char *x) {
    auto x_last = copy_while(x, data_, copy_string_predicate{size_}).first;
    size_ = x_last - x;
  }

  constexpr array_static& operator=(const array_static& x) {
    size_ = x.size_;
    std::copy(x.data_, x.data_ + size_, data_);
    return *this;
  }

  template<typename U>
  constexpr array_static& operator=(const U& x) {
    size_ = x.size();
    std::copy(std::begin(x), std::end(x), data_);
    return *this;
  }

  friend
  inline
  bool operator==(const array_static &x, const array_static &y) {
    return x.size_ == y.size_ && equal_ranges(std::begin(x), std::end(x), std::begin(y));
  }

  friend
  inline
  bool operator!=(const array_static &x, const array_static &y) {
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
    return data_ ;
  }

  iterator end() {
    return data_ + size_;
  }

  const_iterator end() const {
    return data_ + size_;
  }

  reverse_iterator rbegin() {
    return reverse_iterator(data_ + size_ - 1);
  }

  const_reverse_iterator rbegin() const {
    return reverse_iterator(data_ + size_ - 1);
  }

  reverse_iterator rend() {
    return reverse_iterator(data_ - 1);
  }

  const_iterator rend() const {
    return reverse_iterator(data_ - 1);
  }

  constexpr size_type size() const {
    return size_;
  }

  void resize(size_type n) {
    size_ = n;
  }

  size_type capacity() const {
    return N;
  }

  value_type& front() {
    return data_[0];
  }

  const value_type& front() const {
    return data_[0];
  }

  value_type& back() {
    return data_[size_ - 1ul];
  }

  const value_type& back() const {
    return data_[size_ - 1ul];
  }


  void pop_back() {
    --size_;
  }

  void push_back(const value_type &x) {
    data_[size_] = x;
    ++size_;
  }

  void push_back(value_type&& x) {
    data_[size_] = std::move(x);
    ++size_;
  }

  friend
  inline
  bool operator<(const array_static& x, const array_static& y) {
    return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }
};

template<size_t N>
using string_static = array_static<unsigned char, N + 1>; // TODO: WRONG DECISION

typedef string_static<32> string32_t;
typedef string_static<64> string64_t;
typedef string_static<128> string128_t;
typedef string_static<256> string256_t;

} // namespace v1
} // namespace sgl
