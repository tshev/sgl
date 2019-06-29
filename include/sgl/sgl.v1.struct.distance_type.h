#pragma once

namespace sgl {
namespace v1 {

template<typename F>
    requires(Transformation(F))
struct distance_type;

// If all transformations on a type T have the same distance type,
// then DistanceType(T) is defined and returns that type.

// For any fixed-size type T, there is an integral type of the same
// size that is a valid distance type for T.

template<>
struct distance_type<int>
{
    typedef unsigned int type;
};

template<>
struct distance_type<long long>
{
    typedef unsigned long long type;
};

} // namespace v1
} // namespace sgl

#define DistanceType(T) typename sgl::v1::distance_type< T >::type
