namespace sgl {
namespace v1 {


template<size_t i=0, typename Tuple0, typename Tuple1, typename F, typename std::enable_if<!(i < std::tuple_size<Tuple0>::value), bool>::type = false>
inline
void for_each_in_tuple_while(const Tuple0& args0, const Tuple1& args1, F f) {}


template<size_t i=0, typename Tuple0, typename Tuple1, typename F, typename std::enable_if<!(i < std::tuple_size<Tuple0>::value), bool>::type = false>
inline
void for_each_in_tuple_while(Tuple0& args0, Tuple1& args1, F f) {}


template<size_t i=0, typename Tuple0, typename Tuple1, typename F, typename std::enable_if<(i < std::tuple_size<Tuple0>::value), bool>::type = false>
inline
void for_each_in_tuple_while(const Tuple0& args0, const Tuple1& args1, F f) {
	f(std::get<i>(args0), std::get<i>(args1));
	for_each_in_tuple_while<i + 1>(args0, args1, f);
}


template<size_t i=0, typename Tuple0, typename Tuple1, typename F, typename std::enable_if<(i < std::tuple_size<Tuple0>::value), bool>::type = false>
inline
void for_each_in_tuple_while(Tuple0& args0, Tuple1& args1, F f) {
	f(std::get<i>(args0), std::get<i>(args1));
	sgl::v1::for_each_in_tuple_while<i + 1>(args0, args1, f);
}


} // namespace v1
} // namespace sgl
