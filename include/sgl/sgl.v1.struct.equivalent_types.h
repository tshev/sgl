#pragma once
namespace sgl {
namespace v1 {
  template<typename T, typename U>
  struct equivalent_types {
    static constexpr bool value = std::is_same<typename std::remove_reference<T>::type, typename std::remove_reference<U>::type>::value;
  };
} // namespace v1
} // namespace sgl
