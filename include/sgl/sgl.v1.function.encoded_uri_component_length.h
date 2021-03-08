#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename N>
N encoded_uri_component_length(It first, It last, N n) {
    while (first != last) {
        if ((*first >= 'a' && *first <= 'z') || (*first >= 'A' && *first <= 'Z') || (*first >= '0' && *first <= '9')||  *first == '-' || *first == '_' || *first == '.' || *first == '~') {
            ++n;
        } else {
            n += 3;
        }
        ++first;
    }
    return n;
}

template<typename It>
size_t encoded_uri_component_length(It first, It last) {
    return sgl::v1::encoded_uri_component_length(first, last, size_t{0});
}


}
}
