#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename Out>
Out decode_base64(It first, It last, Out out) {
    constexpr const char table[] = {62, 0, 0, 0, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51};
    uint64_t val = 0;
    int64_t valb = -8;
    while (first != last && table[*first - 43] != 0) {
        val = (val << 6) + table[*first - 43];
        valb += 6;
        if (valb >= 0) {
            *out = char((val >> valb) & 0xFF);
            ++out;
            valb -= 8;
        }
        ++first;
    }
    return out;
}

}
}
