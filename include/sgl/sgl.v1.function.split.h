#pragma once
// #include <algorithm>
namespace sgl {
namespace v1 {


template<typename ForwardIterator, typename Predicate, typename Function>
void split_if(ForwardIterator first, ForwardIterator last, Predicate predicate, Function function)  {
    auto start = std::find_if(first, last, predicate);

	while (start != last) {
        first = std::find_if_not(start, last, predicate);
        function(start, first);
        start = std::find_if(first, last, predicate);
	}
}


template<typename ForwardIterator, typename OutputIterator, typename Predicate>
OutputIterator split_copy(ForwardIterator first, ForwardIterator last, OutputIterator output_iterator, Predicate predicate)  {
    auto start = std::find_if(first, last, predicate);

	while (start != last) {
        first = std::find_if_not(start, last, predicate);
        *output_iterator = {start, first};
        ++output_iterator;
        start = std::find_if(first, last, predicate);
	}
  return output_iterator;

}


template<typename ForwardIterator, typename OutputIterator, typename T>
inline
OutputIterator split(ForwardIterator first, ForwardIterator last, OutputIterator out, T sep) {
    while (first != last) {
        auto next = sgl::v1::find(first, last, sep);
        *out = {first, next};
        ++out;
        first = next;
        if (first != last) {
            ++first;
        }
    }
    return out;
}


} // namespace v1
} // namespace sgl
