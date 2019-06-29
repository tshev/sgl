#pragma once
namespace sgl {
namespace v1 {

template<bool, typename T0, typename T1>
struct if_else;

 
template<typename T0, typename T1>
struct if_else<false, T0, T1> {
    typedef T1 value_type;
};


template<typename T0, typename T1>
struct if_else<true, T0, T1> {
    typedef T0 value_type;
};

} // namespace v1
} // namespace sgl
