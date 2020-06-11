#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator>
inline
sgl::v1::triple<ForwardIterator, std::pair<ForwardIterator, ForwardIterator>, std::pair<ForwardIterator, ForwardIterator>> parse_program_option(ForwardIterator first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type T;

    std::pair<ForwardIterator, ForwardIterator> key(last, last);
    std::pair<ForwardIterator, ForwardIterator> value(last, last);

    if (first == last) {
        return {last, key, value};
    }

    key.first = first;

    ForwardIterator first1 = first;
    ++first1;

    if (first1 == last) {
        key.second = first1;
        return {first, key, value};
    }

    first = sgl::v1::find_if(first1, last, sgl::v1::expression_separator{});
    key.second = first;

    if (first == last) {
        value.first = first;
        value.second = first;
        return {first, key, value};
    }

    T separator = *first;

    // if (separator == '=' || separator == ' ') {
    // if (first == last) { return {first, key, value}; }                   // never happens

    ForwardIterator fast = first;
    ++fast;

    if (fast == last) {
        return {first, key, value};
    }

    if (*fast == '\'' || *fast == '"') {
        separator = *fast;
        ++fast;
    } else {
        separator = ' ';
    }
    //}
    if (fast == last || *fast == separator) { return {first, key, value}; }

    first1 = std::adjacent_find(fast, last, [separator](auto x, auto y) { return x != '\\' && y == separator; });

    if (first1 != last)
        ++first1;
    value.first = fast;
    value.second = first1;

    if (first1 == last) {
        return {last, key, value};
    }

    first = first1;
    ++first;

    return {first, key, value};
}
} // namespace v1
} // namespace sgl
