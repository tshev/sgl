#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator0, typename OutputIterator1>
inline
std::pair<OutputIterator0, OutputIterator1> parse_program_options(ForwardIterator first, ForwardIterator last, OutputIterator0 out0, OutputIterator1 out1) {
    while (first != last) {
        if (*first == '-') {
            auto [first_new, key_range, value_range] = sgl::v1::parse_program_option(first, last);
            if (value_range.first == value_range.second || *(value_range.first) == '-') {
                first = key_range.second;
                *out1 = {key_range, std::make_pair(value_range.second, value_range.second)};
            } else {
                first = first_new;
                *out1 = {key_range, value_range};
                ++out1;
            }
        } else {
            sgl::v1::expression_separator expression_separator;
            char separator = ' ';
            if (expression_separator(*first)) {
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
