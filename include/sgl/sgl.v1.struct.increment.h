#pragma once

namespace sgl {
namespace v1 {
template<typename T>
struct increment {
  T& operator()(T& x) const {
    return ++x;
  }
};

template<typename T>
// useless
struct increment_postfix {
  T operator()(T& x) const {
    return x++;
  }
};

template<typename T>
struct increment_by {
  T value;
  increment_by() = default;
  increment_by(const T& value) : value(value) {}

  T& operator()(T& x) const {
    x += value;
    return x;
  }
};

template<typename T>
// useless
struct increment_by_postfix {
  T value;
  increment_by_postfix() = default;
  increment_by_postfix(const T& value) : value(value) {}

  T operator()(T& x) const {
    auto tmp = value;
    x += value;
    return tmp;
  }
};
} // namespace v1
} // namespace sgl
