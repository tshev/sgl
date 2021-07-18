#pragma once
// sgl::depends("struct_totally_ordered");
namespace sgl {
namespace v1 {
template<typename T0, typename T1>
struct pair: totally_ordered<pair<T0, T1> > {
    T0 m0;
    T1 m1;

    friend
    inline
    bool operator==(const pair& x, const pair& y) {
        return x.m0 == y.m0 && x.m1 == y.m1;
    }

    friend
    inline
    bool operator!=(const pair& x, const pair& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const pair& x, const pair& y) {
      return x.m0 < y.m0 || (!(y.m0 < x.m0) && x.m1 < y.m1);
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
  return *x.m0 + *x.m1;
}

template<typename T>
inline
T accumulate(const pair<T, T> &x) {
  return x.m0 + x.m1;
}
} // namespace v1
} // namespace sgl
