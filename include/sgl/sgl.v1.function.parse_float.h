#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename O>
It parse_float(It first, It last, O out) {
    typedef typename std::iterator_traits<O>::value_type T;
    if (first == last) return first;
    It first_integer = first;

    It last_integer = std::find_if(first, last, [](auto x) { return x == '.' || x == 'e'; });

    It first_frac = last_integer;
    It last_frac = last_integer;

    if (last_integer != last && *last_integer == '.') {
        first_frac = last_integer;
        ++first_frac;
        last_frac = std::find(first_frac, last, 'e');
    }
    It exp_first = last_frac;
    if (exp_first != last) ++exp_first;

    T exp = 0;
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
   
    T a0;
    T a1;

    if (exp < 0) {
        a0 = x0 / std::pow(T(10), -exp);
        a1 = x1 / std::pow(T(10), -exp + std::distance(first_frac, last_frac));
    } else {
        a0 = x0 * std::pow(T(10), exp);
        a1 = x1 * std::pow(T(10), exp - std::distance(first_frac, last_frac));
    }

    if (a0 < a1) {
        *out = a0;
        *out += a1;
    } else {
        *out = a1;
        *out += a0;
    }

    return last_exp;
}

} // namespace v1
} // namespace sgl
