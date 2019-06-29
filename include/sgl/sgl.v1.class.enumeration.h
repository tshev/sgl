#include <cstdint>
#include <algorithm>
#include <iostream>


template<typename ForwardIterator, typename MaskType>
struct mask_iterator {
  ForwardIterator iterator;
  MaskType mask;
  MaskType i;

  mask_iterator() = default;
  mask_iterator(const ForwardIterator& iterator, const MaskType& mask) noexcept : iterator(iterator), mask(mask) { next();}
  mask_iterator(const ForwardIterator& iterator, const MaskType& mask, const MaskType& i) noexcept : iterator(iterator), mask(mask), i(i) { next(); }
  mask_iterator(const mask_iterator&) = default;

  mask_iterator& operator=(const mask_iterator& x) {
    iterator = x.iterator;
    mask = x.mask;
    return *this;
  }

  void next() {
    while ((i & mask) == MaskType(0) && i != MaskType{0}) {
      i <<= 1u;
      ++iterator;
    }
  }

  friend
  inline
  bool operator==(const mask_iterator& x, const mask_iterator& y) {
    return x.i == y.i;
  }

  friend
  inline
  bool operator!=(const mask_iterator& x, const mask_iterator& y) {
    return !(x == y);
  }

  mask_iterator& operator++() {
    i <<= 1u;
    ++iterator;
    next();
    return *this;
  }

  auto& operator*() {
    return *iterator;
  }

  const auto& operator*() const {
    return *iterator;
  }
};

template<uint8_t N>
struct enumeration {
  uint64_t value : N;
  enumeration() : value(1u) {}
  enumeration(const enumeration&) = default;
  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  enumeration(const T& value) : value(value) {}


  enumeration& operator=(const enumeration& x) {
    this->value = x.value;
    return *this;
  }
  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  enumeration& operator=(const T& x) {
    value = x.value;
    return *this;
  }

  size_t size() {
    return __builtin_popcountll(value);
  }

  friend
  inline
  bool operator==(const enumeration& x, const enumeration& y) {
    return x.value == y.value;
  }

  friend
  inline
  bool operator!=(const enumeration& x, const enumeration& y) {
    return !(x == y);
  }

  enumeration& operator*() {
    return *this;
  }

  const enumeration& operator*() const {
    return *this;
  }


  enumeration& operator++() {
    ++value;
    return *this;
  }

  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  enumeration& operator<<=(const T& x) {
    value <<= x;
    return *this;
  }

  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  enumeration operator&(const T& x) {
    return enumeration(value & x);
  }

  friend
  inline
  enumeration operator&(const enumeration& x, const enumeration& y) {
    return x.value & y.value;
  }

  template<typename ForwardIterator>
  auto begin(ForwardIterator it) {
    return mask_iterator<ForwardIterator, enumeration>(it, *this, 1);
  }

  template<typename ForwardIterator>
  auto end(ForwardIterator it) {
    return mask_iterator<ForwardIterator, enumeration>(it, *this, 0);
  }

  auto begin() {
    return enumeration(*this);
  }

  auto end() {
    return enumeration(0);
  }
};
