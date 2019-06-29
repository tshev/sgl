#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator0, typename OutputIterator1>
inline
std::pair<OutputIterator0, OutputIterator1> parse_program_options(ForwardIterator first, ForwardIterator last, OutputIterator0 out0, OutputIterator1 out1) {
    while (first != last) {
        if (*first == '-') {
            auto [new_pos, key, value] = sgl::v1::parse_program_option(first, last);
            if (value.first == value.second || *(value.first) == '-') {
                first = key.second;
                *out1 = {key, std::make_pair(value.second, value.second)};
            } else {
                first = new_pos;
                *out1 = {key, value};
                ++out1;
            }
        } else {
            char separator = ' ';
            if (sgl::v1::expression_separator{}(*first)) {
                separator = *first;
                ++first;
            }

            auto second = sgl::v1::find_adjacent_next(first, last, [separator](auto x, auto y) { return x != '\\' && y == separator; });
            *out0 = {first, second};
            ++out0;
            if (second != last) {
                ++second;
            }
            first = second;
        }
        first = sgl::v1::find_not(first, last, ' ');
    }
    return {out0, out1};
}
} // namespace v1
} // namespace sgl
