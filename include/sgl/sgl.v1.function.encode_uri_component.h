#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename Out>
Out encode_uri_component(It first, It last, Out out) {
    const char *hex = "0123456789ABCDEF";
    while (first != last) {
        if ((*first >= 'a' && *first <= 'z') || (*first >= 'A' && *first <= 'Z') || (*first >= '0' && *first <= '9')||  *first == '-' || *first == '_' || *first == '.' || *first == '~') {
            *out = *first;
            ++out;
        } else {
            *out = '%';
            ++out;
            auto c = static_cast<unsigned char>(*first);
            *out = hex[c >> 4];
            ++out;
            *out = hex[c & 15];
            ++out;
        }
        ++first;
    }
    return out;
}

}
}
