#pragma once

namespace sgl {
namespace v1 {

template<typename T>
void _strcat(T& result) { }

template<typename U, typename... T>
void _strcat(std::string& result, const U& x, const T&... tail) {
    size_t total_strlength = strlength(result, x, tail...);
    result.append(x);
    _strcat(result, tail...);
}

template<typename S, typename U, typename... T>
void _strcat(S& result, const U& x, const T&... tail) {
    size_t total_strlength = strlength(result, x, tail...);
    result.append(x);
    _strcat(result, tail...);
}

template<typename U, typename... T>
std::string strcat(const U& x, const T&... tail) {
    std::string result;
    result.reserve(strlength(x, tail...));
    _strcat(result, x, tail...);
    return result;
}

template<typename S, typename U, typename... T>
S strcat(const U& x, const T&... tail) {
    S result;
    result.reserve(strlength(x, tail...));
    _strcat(result, x, tail...);
    return result;
}

} // namespace v1
} // namespace sgl
