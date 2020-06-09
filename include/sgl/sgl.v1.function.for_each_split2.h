#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename T, typename Func>
void for_each_split2(It first, It last, const T& outer, const T& inner, Func function) {
    sgl::v1::for_each_split(first, last, outer, [&inner, &function](auto first, auto last) mutable {
        sgl::v1::for_each_split(first, last, inner, function);
    });
}

} // namespace v1
} // namespace sgl
