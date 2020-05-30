#pragma once

namespace sgl {
namespace v1 {

template<typename It>
int64_t soundex(It first, It last) {
    last = sgl::v1::soundex_squash(first, last);
    if (last - first > 7) {
        int64_t x;
        char* px = (char*)&x;

        *px = *first;
        ++first;
        ++px;

        *px = *first;
        ++first;
        ++px;

        *px = *first;
        ++first;
        ++px;

        *px = *first;
        ++first;
        ++px;

        *px = *first;
        ++first;
        ++px;

        *px = *first;
        ++first;
        ++px;

        *px = *first;
        ++first;
        ++px;

        *px = *first;
        return x;
    }
    int64_t x = 0;
    char* px = (char*)&x;
    if (first != last) { *px = *first; ++px; ++first; } else { return x; }
    if (first != last) { *px = *first; ++px; ++first; } else { return x; }
    if (first != last) { *px = *first; ++px; ++first; } else { return x; }
    if (first != last) { *px = *first; ++px; ++first; } else { return x; }

    if (first != last) { *px = *first; ++px; ++first; } else { return x; }
    if (first != last) { *px = *first; ++px; ++first; } else { return x; }
    if (first != last) { *px = *first; } else { return x; }
    return x;
}

}  // namespace v1
}  // namespace sgl
