#pragma once

namespace sgl {
namespace v1 {

template<typename It>
inline
It find_last(It first, It last, const SGLValueType(It)& value) {
    It result_position = first;
    while (first != last) {
        if (*first == value) {
            result_position = first;
        }
        ++first;
    }
    return result_position;
}


template<typename It, typename R>
inline
It find_last(It first, It last, const SGLValueType(It)& value, R cmp) {
    It result_position = first;
    while (first != last) {
        if (cmp(*first, value)) {
            result_position = first;
        }
        ++first;
    }
    return result_position;
}

} // v1
} // namespace sgl
