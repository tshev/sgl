#pragma once
namespace sgl {
namespace v1 {

template<typename It0, typename It1>
inline
It0 find_subsequence(It0 first0, It0 last0, It1 first1, It1 last1) {
    while (first0 != last0) {
        if (sgl::v1::equal(first0, last0, first1, last1)) {
            return first0;
        }
        ++first0;
    }
    return first0;
}

} // namespace v1
} // namespace sgl
