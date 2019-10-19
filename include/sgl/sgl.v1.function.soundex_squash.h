#pragma once

namespace sgl {
namespace v1 {

constexpr char soundex_table[255] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 97, 98, 99, 100, 97, 98, 99, 97, 97, 99, 99, 76, 109, 109, 97, 98, 99, 82, 99, 100, 97, 98, 97, 99, 89, 99, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 97, 98, 99, 97, 97, 99, 99, 108, 109, 109, 97, 98, 99, 114, 99, 100, 97, 98, 97, 99, 121, 99, 123, 124, 125, 126, 127, -128, -127, -126, -125, -124, -123, -122, -121, -120, -119, -118, -117, -116, -115, -114, -113, -112, -111, -110, -109, -108, -107, -106, -105, -104, -103, -102, -101, -100, -99, -98, -97, -96, -95, -94, -93, -92, -91, -90, -89, -88, -87, -86, -85, -84, -83, -82, -81, -80, -79, -78, -77, -76, -75, -74, -73, -72, -71, -70, -69, -68, -67, -66, -65, -64, -63, -62, -61, -60, -59, -58, -57, -56, -55, -54, -53, -52, -51, -50, -49, -48, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33, -32, -31, -30, -29, -28, -27, -26, -25, -24, -23, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2};


template<typename It>
It soundex_squash(It first, It last) {
    if (first == last) { return first; };
    if (*first > 64 && *first < 91) { *first += 32; }
    ++first;
    auto m = sgl::v1::squash_subgroups_back(first, last, [](auto x, auto y) { return soundex_table[size_t(x)] == soundex_table[size_t(y)]; }, [](auto x) { return soundex_table[size_t(x)]; });
    return m;

}


constexpr
void fill_soundex(char* data) {
    sgl::v1::iota(data, data + 255, 0);
    data[size_t('a')] = 'a';
    data[size_t('e')] = 'a';
    data[size_t('i')] = 'a';
    data[size_t('o')] = 'a';
    data[size_t('u')] = 'a';
    data[size_t('h')] = 'a';
    data[size_t('w')] = 'a';

    data[size_t('b')] = 'b';
    data[size_t('f')] = 'b';
    data[size_t('p')] = 'b';
    data[size_t('v')] = 'b';

    data[size_t('c')] = 'c';
    data[size_t('g')] = 'c';
    data[size_t('j')] = 'c';
    data[size_t('k')] = 'c';
    data[size_t('q')] = 'c';
    data[size_t('s')] = 'c';
    data[size_t('x')] = 'c';
    data[size_t('z')] = 'c';

    data[size_t('d')] = 'd';
    data[size_t('t')] = 'd';
    data[size_t('m')] = 'm';
    data[size_t('n')] = 'm';

    data[size_t('A')] = 'a';
    data[size_t('E')] = 'a';
    data[size_t('I')] = 'a';
    data[size_t('O')] = 'a';
    data[size_t('U')] = 'a';
    data[size_t('H')] = 'a';
    data[size_t('W')] = 'a';

    data[size_t('B')] = 'b';
    data[size_t('F')] = 'b';
    data[size_t('P')] = 'b';
    data[size_t('V')] = 'b';

    data[size_t('C')] = 'c';
    data[size_t('G')] = 'c';
    data[size_t('J')] = 'c';
    data[size_t('K')] = 'c';
    data[size_t('Q')] = 'c';
    data[size_t('S')] = 'c';
    data[size_t('X')] = 'c';
    data[size_t('Z')] = 'c';

    data[size_t('D')] = 'd';
    data[size_t('T')] = 'd';
    data[size_t('M')] = 'm';
    data[size_t('N')] = 'm';
}

} // namespace v1
} // namespace sgl
