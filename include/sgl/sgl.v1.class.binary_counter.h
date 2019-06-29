#pragma once
#include "macros.h"

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename AssociativeOperation>
ValueType(ForwardIterator) binary_counter_reduce(ForwardIterator first, ForwardIterator last, ValueType(ForwardIterator) zero, AssociativeOperation op);

template<typename Operation, typename T = typename Operation::argument_type>
// requires(BinaryOperation)
class binary_counter {
public:
  typedef T value_type;
  typedef Operation operation_type;

private:
  Operation op;
  T zero;
  std::vector<T> data;
public:
  binary_counter() {}
  binary_counter(Operation op) : op(op) {}
  binary_counter(const binary_counter &x) : op(x.op), zero(x.zero), data(x.data) {}

  binary_counter& operator=(const binary_counter &x) {
    op = x.op;
    zero = x.zero;
    data = x.data;
    return *this;
  }

  friend
  inline
  bool operator==(const binary_counter &x, const binary_counter &y) {
    return x.op == y.op && x.zero == y.zero && x.data == y.data;
  }

  friend
  inline
  bool operator!=(const binary_counter &x, const binary_counter &y) {
    return !(x == y);
  }

  binary_counter(binary_counter &&x) : op(std::move(x.op)), zero(std::move(x.zero)), data(std::move(x.data)) {}
  binary_counter& operator=(binary_counter &&x) {
    op = std::move(op);
    zero = std::move(x.zero);
    data = std::move(x.data);
    return *this;
  }

  void push_back(T x) {
    data.push_back(x);
  }

  T reduce() const {
    return binary_counter_reduce(std::begin(data), std::end(data), zero, op);
  }
};

template<typename ForwardIterator, typename AssociativeOperation>
ValueType(ForwardIterator) binary_counter_reduce(ForwardIterator first, ForwardIterator last, ValueType(ForwardIterator) zero, AssociativeOperation op) {
  // while (first != last && *(first++) == zero);
  while (first != last && *first == zero) { ++first; }
 
  ValueType(ForwardIterator) result = *first;

  ++first; 
  while (first != last) {
    if (*first != zero) {
      result = op(result, *first);
    }
    ++first;
  }
  return result;
}
} // namespace v1
} // namespace sgl
