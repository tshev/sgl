#pragma once
namespace sgl {
namespace v1 {

template<typename C>
inline
auto begin(const C& container) {
    return std::begin(container);
}


template<typename C>
inline
auto begin(C& container) {
    return std::begin(container);
}


template<typename T>
inline
auto begin(const std::pair<T, T>& range) {
    return range.first;
}


template<typename T>
inline
auto begin(std::pair<T, T>& range) {
    return range.first;
}


} // namespace v1
} // namespace sgl
