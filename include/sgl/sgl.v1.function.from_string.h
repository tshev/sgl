namespace sgl {
namespace v1 {

template<typename T>
inline
const char* from_string(const char* string, T* value) {
    if constexpr (std::is_number<T>::value) {
        if constexpr (std::is_integer<T>::value) {

            if constexpr (std::is_signed<T>::value) {

            } else {

            }

        } else  if constexpr (std::is_decimal<T>::value) {

        } else if constexpr (std::is_floating_point<T>::value) {

        }
    }
    size_t length = std::strlen(string);
    *value = std::string_view(string, length);
    return string + length;
}

template<typename T>
inline
const char* from_string(const char* first, const char* last, T* value) {

}


}
}
