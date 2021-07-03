#pragma once

namespace sgl {
namespace v1 {

template<typename T, bool is_signed, bool way3>
struct _gcd {};


// TODO: make it has a zero overhead


template<typename N>
struct _gcd<N, false, true> {
    inline
    N operator()(N& m, N& n) const {
        if (sgl::v1::zero(m)) return n;
        if (sgl::v1::zero(n)) return m;

        int d_m = sgl::v1::ctz_inplace(m); 
        int d_n = sgl::v1::ctz_inplace(n);
        // odd(m) && odd(n)
      
        while (m != n) {
            if (m < n) std::swap(n, m);
            m -= n;
            sgl::v1::ctz_inplace(m);
        }

        return m << std::min(d_m, d_n);
    }

    template<typename Cmp>
    inline
    N gcd(N m, N n, Cmp cmp) {
        if (sgl::v1::zero(m)) return n;
        if (sgl::v1::zero(n)) return m;

        int d_m = sgl::v1::ctz_inplace(m); 
        int d_n = sgl::v1::ctz_inplace(n);
        // odd(m) && odd(n)

        while (true) {
            auto cmp_result = cmp(m, n);
            if (sgl::v1::zero(cmp_result)) break;
            if (cmp_result < 0) std::swap(n, m);
            m -= n;
            sgl::v1::ctz_inplace(m);
        }
      
        return m << std::min(d_m, d_n); // handles the overflow
   }
};


template<typename N>
struct _gcd<N, true, true> {

    inline
    N operator()(N& a, N& b) const {
        typedef typename std::make_unsigned<N>::type T;
        T m = static_cast<T>(a); // if (a < N(0)) m = -a else m = a;
        T n = static_cast<T>(b); // if (b < N(0)) n = -b else n = b;

        if (sgl::v1::zero(m)) return n;
        if (sgl::v1::zero(n)) return m;

        int d_m = sgl::v1::ctz_inplace(m); 
        int d_n = sgl::v1::ctz_inplace(n);
        // odd(m) && odd(n)

        while (m != n) {
            if (m < n) std::swap(n, m);
            m -= n;
            sgl::v1::ctz_inplace(m);
        }
        return static_cast<N>(m << std::min(d_m, d_n)); // handles the overflow
    }


    template<typename Cmp>
    inline
    N gcd(N& a, N& b, Cmp cmp) {
        typedef typename std::make_unsigned<N>::type T;
        T m = static_cast<T>(a); // if (a < N(0)) m = -a else m = a;
        T n = static_cast<T>(b); // if (b < N(0)) n = -b else n = b;

        if (sgl::v1::zero(m)) return n;
        if (sgl::v1::zero(n)) return m;

        int d_m = sgl::v1::ctz_inplace(m); 
        int d_n = sgl::v1::ctz_inplace(n);
        // odd(m) && odd(n)

        while (true) {
            auto cmp_result = cmp(m, n);
            if (sgl::v1::zero(cmp_result)) break;
            if (cmp_result < 0) std::swap(n, m);
            m -= n;
            sgl::v1::ctz_inplace(m);
        }
      
        return static_cast<N>(m << std::min(d_m, d_n)); // handles the overflow
    }
};

template <typename N>
inline
N gcd(N m, N n) {
    return sgl::v1::_gcd<N, std::is_signed<N>::value, true>()(m, n);
}

template <typename N, typename Cmp>
inline
N gcd(N m, N n, Cmp cmp) {
    return sgl::v1::_gcd<N, std::is_signed<N>::value, std::is_arithmetic<std::invoke_result_t<Cmp>>::value && !std::is_same<std::invoke_result_t<Cmp>, bool>::value>()(m, n);
}

} // namespace v1
} // namespace sgl
