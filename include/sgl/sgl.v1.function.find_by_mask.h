#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
inline
It0 find_by_mask(It0 first, It0 last, It1 first1) {
    while (first != last && !*first1) {
        ++first;
    }
    return first;
}

}
}
