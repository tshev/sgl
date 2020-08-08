#pragma once
#include <iterator>

#define attributes_packed __attribute__((__packed__))

#define CPP17 201703L

/************************************ Concepts START *********************************/

#if __cplusplus <= CPP17
#ifndef requires
#define requires(...)
#else
#pragma GCC warning "requires is already defined"
#endif
#endif

#if __cplusplus <= CPP17
#define SGLConcept(...)
#else
#define SGLConcept(...) __VA_ARGS__
#endif

#ifndef SGLDifferenceType
#define SGLDifferenceType(It) typename std::iterator_traits<It>::difference_type
#else
#pragma GCC warning "SGLDifferenceType is already defined"
#endif

#ifndef SGLValueType
#define SGLValueType(It) typename std::iterator_traits<It>::value_type
#else
#pragma GCC warning "SGLValueType is already defined"
#endif

#define SGLFirstType(T) typename T::first_type
#define SGLSecondType(T) typename T::second_type
#define SGLElementType(T) typename T::value_type

#ifndef __FUNCTION_NAME__
    #ifdef WIN32   //WINDOWS
        #define __FUNCTION_NAME__   __FUNCTION__  
    #else          //*NIX
        #define __FUNCTION_NAME__   __func__ 
    #endif
#endif

#define PRINT_FUNCTION_NAME() std::cout << __FUNCTION_NAME__ << std::endl;

//#ifndef pointer
//#define pointer(T) T*
//#endif
