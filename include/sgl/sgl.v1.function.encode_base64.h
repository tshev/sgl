#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename Out>
Out _encode_base64(std::random_access_iterator_tag, It first, It last, Out out, size_t n) {
    size_t rem = n % 3;
    last = first + (n - rem);
    constexpr const char* b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    while (first != last) {
        uint32_t v = *first;
        ++first;
        v = (v << 8) | *first;
        ++first; 
        v = (v << 8) | *first;
        ++first;
        
        *out = b64[(v >> 18) & 0x3F];
        ++out; 
        *out = b64[(v >> 12) & 0x3F];
        ++out; 
        *out = b64[(v >> 6) & 0x3F];
        ++out;
        *out = b64[v & 0x3F];
        ++out;
    }

    if (rem == 1) {
        uint32_t v = uint32_t(*first) << 16;
        *out = b64[(v >> 18) & 0x3F];
        ++out;
        *out = b64[(v >> 12) & 0x3F];
        ++out;
        *out = '=';
        ++out;
        *out = '=';
        ++out;
    } else if (rem == 2) {
        uint32_t v = *first;
        ++first;
        v = (v << 8 | *first) << 8;
        *out = b64[(v >> 18) & 0x3F];
        ++out; 
        *out = b64[(v >> 12) & 0x3F];
        ++out;
        *out = b64[(v >> 6) & 0x3F];
        ++out;
        *out = '=';
        ++out;
    }
    return out;
}


template<typename It, typename Out>
Out encode_base64(std::random_access_iterator_tag tag, It first, It last, Out out) {
    return sgl::v1::_encode_base64(tag, first, last, out, size_t(last - first));
}


template<typename It, typename Out>
std::pair<It, Out> encode_base64(std::random_access_iterator_tag, It first, size_t n, Out out) {
    It last = first + n;
    return std::pair<It, Out>(last, sgl::v1::_encode_base64(std::random_access_iterator_tag(), first, last, out, n));
}


template<typename It, typename Out>
std::pair<It, Out> encode_base64(std::forward_iterator_tag, It first, size_t n, Out out) {
    size_t rem = n % 3;
    n -= rem;
    constexpr const char* b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    while (n != 0) {
        uint64_t v = *first;
        ++first; 
        v = (v << 8) | *first;
        ++first;  
        v = (v << 8) | *first;
        ++first;
        
        *out = b64[(v >> 18) & 0x3F];
        ++out; 
        *out = b64[(v >> 12) & 0x3F];
        ++out; 
        *out = b64[(v >> 6) & 0x3F];
        ++out;
        *out = b64[v & 0x3F];
        ++out;

        n -= 3;
    }

    if (rem == 1) {
        uint64_t v = uint64_t(*first) << 16;
        ++first;
        *out = b64[(v >> 18) & 0x3F];
        ++out;
        *out = b64[(v >> 12) & 0x3F];
        ++out;
        *out = '=';
        ++out;
        *out = '=';
        ++out;
    } else if (rem == 2) {
        uint64_t v = *first; 
        ++first;
        v = (v << 8 | *first) << 8;
        ++first;
        *out = b64[(v >> 18) & 0x3F];
        ++out; 
        *out = b64[(v >> 12) & 0x3F];
        ++out;
        *out = b64[(v >> 6) & 0x3F];
        ++out;
        *out = '=';
        ++out;
    }
    return {first, out};
}


template<typename It, typename Out>
Out encode_base64(It first, It last, Out out) {
    typedef typename std::iterator_traits<It>::iterator_category iterator_category;
    return sgl::v1::encode_base64(iterator_category(), first, last, out);
}


template<typename It, typename Out>
std::pair<It, Out> encode_base64(It first, size_t n, Out out) {
    typedef typename std::iterator_traits<It>::iterator_category iterator_category;
    return sgl::v1::encode_base64(iterator_category(), first, n, out);
}

} // namespace v1
} // namespace sgl
