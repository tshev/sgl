#pragma once

namespace sgl {
namespace v1 {

template<typename T, int i>
//requires(FunctionalProcedure(T))
struct input_type;

template<typename T>
//requires(Regular(T))
struct input_type<T (*)(T x, T y), 0>
{
    typedef T type;
};

template<typename T>
   //requires(Regular(T))
struct input_type<T (*)(const T& x, const T& y), 0>
{
    typedef T type;
};

template<typename T>
   //requires(Regular(T))
struct input_type<bool (*)(T x), 0>
{
    typedef T type;
};

template<typename T>
   //requires(Regular(T))
struct input_type<bool (*)(const T& x), 0>
{
    typedef T type;
};


// Domain type function for Relation

template<typename T>
   //requires(Regular(T))
struct input_type<bool (*)(T x, T y), 0>
{
    typedef T type;
};

template<typename T>
   //requires(Regular(T))
struct input_type<bool (*)(const T& x, const T& y), 0>
{
    typedef T type;
};


} // namespace v1
} // namespace sgl


#define InputType(T, i) typename sgl::v1::input_type< T, i >::type
#define Domain(T) InputType(T, 0)
