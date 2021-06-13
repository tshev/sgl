#pragma once

namespace sgl {
namespace v1 {
template<typename ForwardIterator0, typename Function>
void for_each_subwindow(ForwardIterator0 first, ForwardIterator0 middle, ForwardIterator0 last, Function function) {
    function(first, middle);
    while (middle != last) {
        ++first;
        ++middle;
        function(first, middle);
    }
    // return first;
}

} // namespace v1
} // namespace sgl
