#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator, typename Predicate>
inline
std::pair<ForwardIterator, OutputIterator> copy_n_while(ForwardIterator first, size_t n, OutputIterator output, Predicate pred) {
    while (n != 0 && pred(*first)) {
        *output = *first;
        --n;
        ++first;
        ++output;
    }
    return {first, output};
}

} // namespace v1
} // namespace sgl
