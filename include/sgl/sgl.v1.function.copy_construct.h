#pragma once
namespace sgl {
namespace v1 {
template<typename Pointer, typename T>
inline
void copy_construct(Pointer first, Pointer last, const T& x) {
    while (first != last) {
        new (std::addressof(*first)) T(x);
        ++first;
    }
}
} // namespace v1
} // namespace sgl
