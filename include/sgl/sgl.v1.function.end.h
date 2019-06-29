#pragma once
namespace sgl {
namespace v1 {

template<typename C>
inline
auto end(const C& container) {
    return std::end(container);
}


template<typename C>
inline
auto end(C& container) {
    return std::end(container);
}


template<typename T>
inline
auto end(const std::pair<T, T>& range) {
    return range.second;
}


template<typename T>
inline
auto end(std::pair<T, T>& range) {
    return range.second;
}


} // namespace v1
} // namespace sgl
