#pragma once

/*
 * # The basic idea
 * ```cpp
 * typedef enumeration_static<24> bust_t;

 * bust_t max = ~0;
 * size_t total_s = 0;

 * for (bust_t s = 0u; s != max; ++s) {
 *   for (bust_t i = 1; i != bust_t{0}; i <<= 1u) {
 *     total_s += ((i & s) != bust_t{0});
 *   }
 * }
 * for (bust_t i = 1; i != 0; i <<= 1u) {
 *   total_s += ((i & max) != bust_t{0});
 * }

 * std::cout << total_s << std::endl;
 * ```
**/

namespace sgl {
template<typename ForwardIterator, typename StaticMaskType>
struct enumeration_static : totally_ordered<enumeration_static<ForwardIterator, StaticMaskType>> {
  typedef ForwardIterator iterator_type;
  typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
  typedef StaticMaskType mask_type;

  ForwardIterator iterator;
  StaticMaskType mask;
  StaticMaskType i;

  enumeration_static() = default;
  enumeration_static(const ForwardIterator& iterator, const StaticMaskType& mask) noexcept : iterator(iterator), mask(mask) { next();}
  enumeration_static(const ForwardIterator& iterator, const StaticMaskType& mask, const StaticMaskType& i) noexcept : iterator(iterator), mask(mask), i(i) { next(); }
  enumeration_static(const enumeration_static&) = default;

  enumeration_static& operator=(const enumeration_static& x) {
    iterator = x.iterator;
    mask = x.mask;
    return *this;
  }

  friend
  inline
  bool operator==(const enumeration_static& x, const enumeration_static& y) {
    return x.i == y.i;
  }

  friend
  inline
  bool operator!=(const enumeration_static& x, const enumeration_static& y) {
    return !(x == y);
  }


  friend
  inline
  bool operator<(const enumeration_static& x, const enumeration_static& y) {
    return x.i < y.i;
  }

  enumeration_static& operator++() {
    step_forward();
    next();
    return *this;
  }

  auto& operator*() {
    return *iterator;
  }

  const auto& operator*() const {
    return *iterator;
  }

  void next() {
    while ((i & mask) == StaticMaskType(0) && i != StaticMaskType(0)) {
      step_forward();
    }
  }

  void step_forward() {
    i <<= StaticMaskType(1u);
    ++iterator;
  }
}; // struct enumeration_static


template<typename T, uint8_t N>
struct enumeration_static : sgl::totally_ordered<enumeration_static<T, N>> {
  T value : N;

  enumeration_static() : value(1u) {}
  template<typename U>
  enumeration_static(const U& value) : value(value) {}
  enumeration_static(const enumeration_static&) = default;

  enumeration_static& operator=(const enumeration_static& x) {
    value = x.value;
    return *this;
  }

  friend
  inline
  bool operator==(const enumeration_static& x, const enumeration_static& y) {
    return x.value == y.value;
  }

  friend
  inline
  bool operator!=(const enumeration_static& x, const enumeration_static& y) {
    return !(x == y);
  }

  friend
  inline
  bool operator<(const enumeration_static& x, const enumeration_static& y) {
    return x.value < y.value;
  }

  friend
  inline
  enumeration_static& operator<<(const enumeration_static& x, const enumeration_static& y) {
    return enumeration_static(x.value << y.value);
  }

  friend
  inline
  enumeration_static operator&(const enumeration_static& x, const enumeration_static& y) {
    return enumeration_static(x.value & y.value);
  }

  template<typename ForwardIterator>
  auto begin(ForwardIterator it) const {
    return enumeration_static<ForwardIterator, enumeration_static>(it, *this, 1u);
  }

  template<typename ForwardIterator>
  auto end(ForwardIterator it) const {
    return enumeration_static<ForwardIterator, enumeration_static>(it, *this, 0u);
  }

  enumeration_static& operator*() {
    return *this;
  }

  const enumeration_static& operator*() const {
    return *this;
  }

  enumeration_static& operator++() {
    ++value;
    return *this;
  }

  enumeration_static& operator<<=(const enumeration_static& x) {
    value <<= x.value;
    return *this;
  }

  auto begin() {
    return enumeration_static(*this);
  }

  auto end() {
    return enumeration_static(0);
  }
}; // struct enumeration_static
} // namespace sgl
