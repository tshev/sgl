#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
// requires(BidirectionalIterator(It0) && BidirectionalIterator(It1))
inline
It0 find_by_mask_backward(It0 first, It0 last, It1 last1) {
    if (first == last) {
        return last;
    }

    auto rlast = last;
    --last;
    --last1;

    while (!*last1 && first != last) {
        --last;
        --last1;
    }

    if (*last1) { 
        return last;
    }

    return rlast;
}

}
}
