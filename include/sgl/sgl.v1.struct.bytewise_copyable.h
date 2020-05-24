#pragma once

namespace sgl {
namespace v1 {

// Do it for any class member by member
// Think about a case with different paddings

template<typename T>
struct bytewise_copyable {
    static constexpr const bool value = std::is_trivial<T>::value;
};


template<typename T0, typename T1>
struct bytewise_copyable<std::pair<T0, T1>> {
    static constexpr const bool value = bytewise_copyable<T0>::value && bytewise_copyable<T1>::value;
};


template<typename T>
struct bytewise_copyable<std::tuple<T>> {
    static constexpr const bool value = bytewise_copyable<T>::value;
};


template<typename T, typename... U>
struct bytewise_copyable<std::tuple<T, U...>> {
    static constexpr const bool value = bytewise_copyable<T>::value && bytewise_copyable<U...>::value;
};

} // namespace v1
} // namespace sgl
