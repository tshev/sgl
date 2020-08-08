#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename T = SGLValueType(It)>
requires(sgl::v1::forward_iterator<It> && sgl::v1::readable<It> && sgl::v1::regular<T>)
It find_unbounded(It first, const T& value) {
    while (*first != value) {
        ++first;
    }
    return first;
}

} // namespace v1
} // namespace sgl
