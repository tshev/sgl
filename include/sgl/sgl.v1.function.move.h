#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename Out>
inline
Out move(It first, It last, Out out) {
    while (first != last) {
        *out = std::move(*first);
        ++out;
        ++first;
    }
    return out;
}

} // namespace v1
} // namespace sgl
