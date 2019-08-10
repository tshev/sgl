#pragma once
namespace sgl {
namespace v1 {

template<typename It0, typename It1, typename F>
inline
void for_each_value_in_map(It0 f0, It0 l0, It1 m, F f) {
    while (f0 != l0) {
        f(m[*f0]);
        ++f0;
    }
}

} // namespace v1
} // namespace sgl
