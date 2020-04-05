#pragma once

namespace sgl {
namespace v1 {

template<typename Integer, typename BidirectionalIterator>
inline
BidirectionalIterator ubase10(Integer value, BidirectionalIterator out_first) {
    BidirectionalIterator out_last = out_first;
    while (true) {
        // there is an instruction, which does division with remainder
        // yes, we can `optimize` this code, but I'll leave this task for Alexandrescu
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
