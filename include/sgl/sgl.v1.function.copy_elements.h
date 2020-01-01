#pragma once

namespace sgl {
namespace v1 {


template<typename It, typename Out>
inline
Out copy_elements(It first, It last, Out out) {
    while (first != last) {
        *out = *first;
        ++first;
        ++out;
    }
    return out;
}

} // namespace v1
} // namespace sgl
