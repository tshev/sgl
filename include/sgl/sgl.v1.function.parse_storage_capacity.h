#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename O>
It parse_storage_capacity(It first, It last, O v) {
    auto e = sgl::v1::parse_uint(first, last, v);
    if (e == first) {
        return first;
    }

    if (last - e == 1) {
        if  (*e == 'G') {
            *v *= 1024 * 1024 * 1024;
            return last;
        }

        if (*e == 'M') {
            *v *= 1024 * 1024;
            return last;
        }
    }

    return e;
}

}
}
