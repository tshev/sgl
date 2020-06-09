#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename T, typename Func>
void for_each_split3(It first, It last, const T& outer, const T& inner, const T& l3, Func function) {
    sgl::v1::for_each_split(first, last, outer, [&inner, &l3, &function](auto first, auto last) mutable {
        sgl::v1::for_each_split(first, last, inner, [&l3, &function](auto first, auto last) {
            sgl::v1::for_each_split(first, last, l3, function);
        });
    });
}

} // namespace v1
} // namespace sgl
