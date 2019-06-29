#pragma once

namespace sgl {
namespace v1 {
template<typename T, typename S = size_t>
struct array_view {
  typedef T value_type;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef S size_type;

  uint8_t* data_;

  array_view(uint8_t* data) : data_(data + 2 * sizeof(size_type)) {}

  array_view(const array_view& x) : data_(x.data_) {}

  size_type* capacity_ptr() {
    return reinterpret_cast<size_type*>(data_ - 2 * sizeof(size_type));
  }

  const size_type* capacity_ptr() const {
    return reinterpret_cast<const size_type*>(data_ - 2 * sizeof(size_type));
  }

  size_type* size_ptr() {
    return reinterpret_cast<size_type*>(data_ - sizeof(size_type));
  }

  const size_type* size_ptr() const {
    return reinterpret_cast<const size_type*>(data_ - sizeof(size_type));
  }

  size_type& capacity() {
    return *capacity_ptr();
  }

  const size_type& capacity() const {
    return *capacity_ptr();
  }

  size_type& size() {
    return *size_ptr();
  }

  const size_type& size() const {
    return *size_ptr();
  }

  T& operator[](size_type i) {
    return data()[i];
  }

  const T& operator[](size_type i) const {
    return  data()[i];
  }

  void push_back(const T& x) {
    data()[size()] = x;
    ++size();
  }

  template<typename... U>
  void emplace_back(U&&... args) {
    new (data() + size())T(std::forward<U>(args)...);
    ++size();
  }


  T& back() {
    return data()[size() - 1];
  }

  const T& back() const {
    return data()[size() - 1];
  }

  void pop_back() {
    --size();
  }

  void resize(size_type n) {
    size() = n;
  }

  uint8_t* raw_data() {
    return data_ - 2 * sizeof(size_type);
  }

  const uint8_t* raw_data() const {
    return data_ - 2 * sizeof(size_type);
  }

  pointer data() {
    return reinterpret_cast<T*>(data_);
  }

  const_pointer data() const {
    return reinterpret_cast<T*>(data_);
  }

  iterator begin() {
    return data();
  }

  iterator end() {
    return begin() + size();
  }

  const_iterator begin() const {
    return data();
  }

  const_iterator end() const {
    return begin() + size();
  }
}; // struct array_view
} // namespace v1
} // namespace sgl
