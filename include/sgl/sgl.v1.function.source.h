#pragma once
namespace sgl {
namespace v1 {

template<typename T>
class _has_source {
    template<typename U>
    static uint8_t _value(decltype(&U::source));

    template<typename U>
    static uint16_t _value(...);    

public:
    static constexpr const bool value = sizeof(_value<typename std::decay<T>::type>(nullptr)) == 1;
};


// TODO: think about value-semantics vs ref-ref and about decay presence
template<typename It>
auto source(const It& it) -> const typename std::enable_if<sgl::v1::_has_source<It>::value, typename std::decay<decltype(it.source())>::type>::type {
    return it.source();
}

template<typename T>
const auto& source(T* it) {
    return *it;
}

template<typename It>
auto source(const It& it) -> const typename std::enable_if<!sgl::v1::_has_source<It>::value, typename std::decay<decltype(*it)>::type>::type& {
    return *it;
}

} // namespace v1
} // namespace sgl
