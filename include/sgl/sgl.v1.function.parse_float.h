#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename ForwardIterator>
It parse_float(It first, It last, ForwardIterator out) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type T;
    typedef typename std::iterator_traits<ForwardIterator>::difference_type D;
    if (first == last) return first;
    It first_integer = first;

    It last_integer = sgl::v1::find_if(first, last, [](auto x) { return x == '.' || x == 'e'; });

    It first_frac = last_integer;
    It last_frac = last_integer;

    if (last_integer != last && *last_integer == '.') {
        first_frac = last_integer;
        ++first_frac;
        last_frac = sgl::v1::find(first_frac, last, 'e');
    }
    It exp_first = last_frac;
    if (exp_first != last) ++exp_first;

    D exp = 0;
    if (exp_first != last && *exp_first == '+') { ++exp_first; }
    auto last_exp = sgl::v1::parse_int(exp_first, last, &exp);
    if (last_exp != last) {
        return last_exp;
    }


    T x0 = 0;
    auto p0 = sgl::v1::parse_int(first_integer, last_integer, &x0);
    if (p0 != last_integer) return p0;

    T x1 = 0;
    auto p1 = sgl::v1::parse_int(first_frac, last_frac, &x1);
    if (p1 != last_frac) return p1;
   

    if (exp < 0) {
        x0 = x0 / sgl::v1::pow(T(10), -exp);
        x1 = x1 / sgl::v1::pow(T(10), -exp + sgl::v1::distance(first_frac, last_frac));
    } else {
        x0 = x0 * sgl::v1::pow(T(10), exp);
        x1 = x1 * sgl::v1::pow(T(10), exp - sgl::v1::distance(first_frac, last_frac));
    }

    if (x0 < x1) {
        *out = x0;
        *out += x1;
    } else {
        *out = x1;
        *out += x0;
    }

    return last_exp;
}

} // namespace v1
} // namespace sgl
