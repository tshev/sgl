#pragma once
namespace sgl {
namespace v1 {

template<typename It0, typename It1, typename OutputIterator, typename F>
inline
OutputIterator transform_values_in_map(It0 f0, It0 l0, It1 m, OutputIterator out, F f) {
    while (f0 != l0) {
        *out = f(m[*f0]);
        ++f0;
        ++out;
    }
    return out;
}

} // namespace v1
} // namespace sgl
