#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
inline
std::pair<It0, It1> find_by_mask(It0 first0, It0 last0, It1 first1) {
    while (first0 != last0 && !*first1) {
        ++first0;
        ++first1;
    }
    return {first0, first1};
}

} // namespace v1
} // namespace sgl
