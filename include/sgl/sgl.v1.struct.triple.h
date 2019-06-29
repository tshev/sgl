#pragma once
// sgl::depends("struct_totally_ordered");
namespace sgl {
namespace v1 {
template<typename T0, typename T1, typename T2>
struct triple : totally_ordered<triple<T0, T1, T2> > {
    T0 first;
    T1 second;
    T2 third;

    triple(const T0& first, const T1& second, const T2& third)
        noexcept(std::is_nothrow_copy_constructible<T0>::value && std::is_nothrow_copy_constructible<T1>::value && std::is_nothrow_copy_constructible<T2>::value)
        : first(first), second(second), third(third) {}

    triple(T0&& first, T1&& second, T2&& third)
        noexcept(std::is_nothrow_move_constructible<T0>::value && std::is_nothrow_move_constructible<T1>::value && std::is_nothrow_move_constructible<T2>::value)
        : first(std::move(first)), second(std::move(second)), third(std::move(third)) {}

    triple& operator=(const triple& x) noexcept(std::is_nothrow_assignable<T0, T0>::value && std::is_nothrow_assignable<T1, T1>::value && std::is_nothrow_assignable<T2, T2>::value) {
        first = x.first;
        second = x.second;
        third = x.third;
        return *this;
    }

    triple& operator=(triple&& x) noexcept(std::is_nothrow_move_assignable<T0>::value && std::is_nothrow_move_assignable<T1>::value && std::is_nothrow_move_assignable<T2>::value)  {
        first = std::move(x.first);
        second = std::move(x.second);
        third = std::move(x.third);
        return *this;
    }

    friend
    inline
    bool operator==(const triple& x, const triple& y) {
        return x.first == y.first && x.second == y.second && x.third == y.third;
    }

    friend
    inline
    bool operator!=(const triple& x, const triple& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const triple& x, const triple& y) {
      return x.first < y.first || (!(y.first < x.first) && x.second < y.second) || (!(y.second < x.second) && x.third < y.third);
    }
}; // struct triple

template <class _Tp>
struct make_triple_return_impl
{
    typedef _Tp type;
};

template <class _Tp>
struct make_triple_return_impl<std::reference_wrapper<_Tp>>
{
    typedef _Tp& type;
};

template <class _Tp>
struct make_triple_return
{
    typedef typename sgl::v1::make_triple_return_impl<typename std::decay<_Tp>::type>::type type;
};


template<typename T0, typename T1, typename T2>
inline
sgl::v1::triple<
  typename sgl::v1::make_triple_return<T0>::type,
  typename sgl::v1::make_triple_return<T1>::type,
  typename sgl::v1::make_triple_return<T2>::type
>
make_triple(T0&& x, T1&& y, T2&& z) {
  typedef sgl::v1::triple<
    typename sgl::v1::make_triple_return<T0>::type,
    typename sgl::v1::make_triple_return<T1>::type,
    typename sgl::v1::make_triple_return<T2>::type
  > triple_type;
  return triple_type(std::forward<T0>(x), std::forward<T1>(y), std::forward<T2>(z));
}

/*
template<typename T>
inline
T accumulate_dereference(const triple<T, T, T>& x) {
  return *x.first + *x.second + *x.third;
}
*/


template<typename T>
inline
T accumulate(const triple<T, T, T>& x) {
  return x.first + x.second + x.third;
}


template<typename T>
using triple_homogeneous = triple<T, T, T>;


template<typename T>
using homogeneous_triple = triple<T, T, T>;
} // namespace v1
} // namespace sgl
