#pragma once

namespace sgl {
namespace v1 {

template<typename InputIterator0, typename InputIterator1, typename Function>
inline
InputIterator1 transform_positions(InputIterator0 first, InputIterator0 last, InputIterator1 out, Function func) {
    while (first != last) {
        func(first, out);
        ++first;
        ++out;
    }
    return out;
}

}
}
