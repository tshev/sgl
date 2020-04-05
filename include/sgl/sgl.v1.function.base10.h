#pragma once

namespace sgl {
namespace v1 {

template<typename Integer, typename BidirectionalIterator>
inline
BidirectionalIterator base10(Integer value, BidirectionalIterator out_first) {
    if (value < 0) {
        *out_first = '-';
        ++out_first;
        value = -value;
    }

    auto out_last = out_first;
    while (true) {
        auto div = value / Integer(10);
        auto rem = value % Integer(10);
        *out_last = rem + Integer(48);
        ++out_last;
        value = div;
        if (value == 0) break;
    }
    std::reverse(out_first, out_last);
    return out_last;
}

} // namespace v1
} // namespace sgl
