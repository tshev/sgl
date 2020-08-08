#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename R, typename T = SGLValueType(It)>
requires(sgl::v1::forward_iterator<It> && sgl::v1::readable<It> && sgl::v1::predicate<R, T>)
It find_if_unbounded(It first, R predicate) {
    while (!predicate(*first)) {
        ++first;
    }
    return first;
}

} // namespace v1
} // namespace sgl
