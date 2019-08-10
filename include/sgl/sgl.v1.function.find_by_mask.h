#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
inline
std::pair<It0, It1> find_by_mask(It0 first, It0 last, It1 first1) {
    while (first != last && !*first1) {
        ++first;
        ++first1;
    }
    return {first, first1};
}

} // namespace v1
} // namespace sgl
