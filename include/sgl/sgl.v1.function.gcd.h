#pragma onace

namespace sgl {
namespace v1 {

template <typename N>
inline
typename std::enable_if<!std::is_signed<N>::value, N>::type gcd(N m, N n) {
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


template <typename N>
inline
typename std::enable_if<std::is_signed<N>::value, N>::type gcd(N a, N b) {
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

} // namespace v1
} // namespace sgl
