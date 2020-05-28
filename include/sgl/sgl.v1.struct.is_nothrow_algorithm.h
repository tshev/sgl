#pragma once
namespace sgl {
namespace v1 {

template<typename... T>
struct is_nothrow_algorithm_internal;


template<typename T, typename It0, typename ... It>
struct is_nothrow_algorithm_internal<T, It0, It...> {
    static constexpr const bool value = sgl::v1::is_nothrow_algorithm_internal<T, It0>::value &&
                                        sgl::v1::is_nothrow_algorithm_internal<T, It...>::value;
};

template<typename T, typename It>
struct is_nothrow_algorithm_internal<T, It> {
    static constexpr const bool value = std::is_same<T, typename std::iterator_traits<It>::value_type>::value &&
                                        std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value;
};

template<typename... T>
struct is_nothrow_algorithm;

template<typename T, typename It0, typename ... It>
struct is_nothrow_algorithm<T, It0, It...> {
    static constexpr const bool value = sgl::v1::is_nothrow_copyable<T>::value &&
                                        sgl::v1::is_nothrow_algorithm_internal<T, It0>::value &&
                                        sgl::v1::is_nothrow_algorithm_internal<T, It...>::value;
};

template<typename T, typename It>
struct is_nothrow_algorithm<T, It> {
    static constexpr const bool value = sgl::v1::is_nothrow_copyable<T>::value &&
                                        sgl::v1::is_nothrow_algorithm_internal<T, It>::value;
};

template<typename T>
struct is_nothrow_algorithm<T> {
    static constexpr const bool value = sgl::v1::is_nothrow_copyable<T>::value;
};

}  // namespace v1
}  // namespace sgl
