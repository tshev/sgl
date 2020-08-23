#pragma once
namespace sgl {
namespace v1 {

template<typename T>
class _has_sink {
    template<typename U>
    static uint8_t _value(decltype(&U::sink));

    template<typename U>
    static uint16_t _value(...);    

public:
    static constexpr const bool value = sizeof(_value<typename std::decay<T>::type>(nullptr)) == 1;
};

// TODO: think about value-semantics vs ref-ref and about decay presence
template<typename It>
auto sink(It&& it) -> typename std::enable_if<sgl::v1::_has_sink<It>::value, typename std::decay<decltype(it.sink())>::type>::type {
    return it.sink();
}


template<typename It>
auto sink(It&& it) -> typename std::enable_if<!sgl::v1::_has_sink<It>::value, typename std::decay<decltype(*it)>::type>::type& {
    return *it;
}


} // namespace v1
} // namespace sgl

