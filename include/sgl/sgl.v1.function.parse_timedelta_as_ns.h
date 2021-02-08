#pragma once
namespace sgl {
namespace v1 {
// TODO I a bad function: rewrite me
template<typename It, typename Out>
inline
It parse_timedelta_as_ns(It first, It last, Out out) {
    auto e = sgl::v1::parse_uint(first, last, out);
    if (e == first) {
        return first;
    }

    if ((last - e == 1 && (*e == 's' || *e == 'S'))) {
        *out *= 1000000000ull;
        return last;
    }

    if (last - e == 2 && ((e[0] == 'm' && e[1] == 's') || (e[0] == 'M' && e[1] == 'S'))) {
        *out *= 1000000ull;
        return last;
    }

    if (last - e == 2 && ((e[0] == 'n' && e[1] == 's') || (e[0] == 'N' && e[1] == 'S'))) {
        return last;
    }
    return e;
}

}
}
