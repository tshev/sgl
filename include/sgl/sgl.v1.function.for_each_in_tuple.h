#pragma once

namespace sgl {
namespace v1 {

template<size_t i=0, typename Tuple, typename F, typename std::enable_if<!(i < sgl::v1::tuple_size<Tuple>::value), bool>::type = false>
inline
void for_each_in_tuple(Tuple& args, F f) {}


template<size_t i=0, typename Tuple, typename F, typename std::enable_if<!(i < sgl::v1::tuple_size<Tuple>::value), bool>::type = false>
inline
void for_each_in_tuple(const Tuple& args, F f) {}


template<size_t i=0, typename Tuple, typename F, typename std::enable_if<(i < sgl::v1::tuple_size<Tuple>::value), bool>::type = false>
inline
void for_each_in_tuple(Tuple& args, F f) {
	f(std::get<i>(args));
	sgl::v1::for_each_in_tuple<i + 1>(args, f);
}


template<size_t i=0, typename Tuple, typename F, typename std::enable_if<(i < sgl::v1::tuple_size<Tuple>::value), bool>::type = false>
inline
void for_each_in_tuple(const Tuple& args, F f) {
	f(std::get<i>(args));
	sgl::v1::for_each_in_tuple<i + 1>(args, f);
}

} // namespace v1
} // namespace sgl
