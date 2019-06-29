#pragma once
// sgl::depends("struct_totally_ordered");
namespace sgl {
namespace v1 {
template<typename T0, typename T1>
struct pair: totally_ordered<pair<T0, T1> > {
    T0 first;
    T1 second;

    friend
    inline
    bool operator==(const pair& x, const pair& y) {
        return x.first == y.first && x.second == y.second;
    }

    friend
    inline
    bool operator!=(const pair& x, const pair& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const pair& x, const pair& y) {
      return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
    }
}; // struct pair

template<typename T0, typename T1>
inline
pair<T0, T1> make_pair(T0&& x, T1&& y) {
  return pair<T0, T1>(std::forward<T0>(x), std::forward<T1>(y));
}

template<typename T>
inline
T accumulate_dereference(const pair<T, T> &x) {
  return *x.first + *x.second;
}

template<typename T>
inline
T accumulate(const pair<T, T> &x) {
  return x.first + x.second;
}
} // namespace v1
} // namespace sgl
