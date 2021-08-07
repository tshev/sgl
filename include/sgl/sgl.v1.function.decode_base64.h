#pragma once
namespace sgl {
namespace v1 {
// TODO: think about concatenated base64 encodings (I think we must ignore this case) No-no: `MQ==Mg==`

template<typename It, typename Out>
Out decode_base64(std::input_iterator_tag, It first, It last, Out out) {
    /*
    constexpr const char table[] = {62, 0, 0, 0, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51};
    uint32_t val = 0;
    int32_t valb = -8;
    while (first != last) {
        auto v = table[*first - 43];
        if (v == 0) break;
        val = (val << 6) + v;
        valb += 6;
        if (valb >= 0) { // bad branch
            *out = char((val >> valb) & 0xFF);
            ++out;
            valb -= 8;
        }
        ++first;
    }
    return out;
    */
    constexpr const char b64[] = {
        62, 63, 62, 62, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0,  0,  0,  0,  0,  0,
        0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0,  0,  0,  0,  63,
        0,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
    };
    while (first != last) {
        uint32_t n = b64[*first - 43] << 18;
        ++first;
        //if (first == last) break; // unnecessary
        n |= b64[*first - 43] << 12 ;
        ++first;
        *out = n >> 16;
        ++out;

        if (first == last) break;
        auto v3 = *first;
        if (v3 == '=') break;

        n |= b64[v3 - 43] << 6;
        ++first;
        *out = (n >> 8) & 0xFF;
        ++out;

        if (first == last) break;
        auto v4 = *first;
        if (v4 == '=') break;

        n |= b64[v4 - 43];
        *out = n & 0xFF;
        ++out;
        ++first;
    }
    return out;
}


template<typename It, typename Out>
std::pair<It, Out> decode_base64(std::input_iterator_tag, It first, size_t n, Out out) {
    constexpr const char table[] = {
        62, 0, 0, 0, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
    };
    uint32_t val = 0;
    int32_t valb = -8;
    while (n != 0) {
        auto v = table[*first - 43];
        if (v == 0) break;
        val = (val << 6) + v;
        valb += 6;
        if (valb >= 0) {
            *out = char((val >> valb) & 0xFF);
            ++out;
            valb -= 8;
        }
        --n;
        ++first;
    }
    return {first, out};
}


template<typename It, typename Out>
Out _decode_base64(std::random_access_iterator_tag, It first, It last, Out out, size_t n) {
    constexpr const char b64[] = {
        62, 63, 62, 62, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0,  0,  0,  0,  0,  0,
        0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0,  0,  0,  0,  63,
        0,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
    };
    It first1 = first;
    size_t rem = n % 4;

    int pad1 = rem || *(last - 1) == '=';
    const size_t k = (n - pad1) / 4 << 2;
    int pad2 = pad1 && (rem > 2 || *(last - 2) != '=');
    auto last1 = first1 + k;

    while (first1 != last1) {
        uint32_t n = b64[*first1 - 43] << 18;
        ++first1;
        n |= b64[*first1 - 43] << 12 ;
        ++first1;
        n |= b64[*first1 - 43] << 6;
        ++first1;
        n |= b64[*first1 - 43];
        ++first1;
        *out = n >> 16;
        ++out;
        *out = n >> 8 & 0xFF;
        ++out;
        *out = n & 0xFF;
        ++out;
    }
    if (pad1) {
        auto x1 = *first1;
        ++first1;
        auto x2 = *first1;
        --last;
        auto v1 = *last;
        uint32_t n = b64[x1 - 43] << 18 | b64[x2 - 43] << 12;
        *out = n >> 16;
        ++out;
        if (pad2)  {
            ++first1;
            n |= b64[*first1 - 43] << 6;
            *out = n >> 8 & 0xFF;
            ++out;
        }
    }
    return out;
}

template<typename It, typename Out>
Out decode_base64(std::random_access_iterator_tag, It first, It last, Out out) {
    return sgl::v1::_decode_base64(std::random_access_iterator_tag(), first, last, out, size_t(last - first));
}

template<typename It, typename Out>
std::pair<It, Out> decode_base64(std::random_access_iterator_tag, It first, size_t n, Out out) {
    auto last = first + n;
    return {
        last,
        sgl::v1::_decode_base64(std::random_access_iterator_tag(), first, last, out, n)
    };
}



template<typename It, typename Out>
Out decode_base64(It first, It last, Out out) {
    typedef typename std::iterator_traits<It>::iterator_category iterator_category;
    return sgl::v1::decode_base64(iterator_category(), first, last, out);

}

}
}
