namespace sgl {
namespace v1 {

template<typename I>
concept readable = requires(I it) {
    //typename std::iterator_traits<I>::value_type value = *it;
    *it;
};

} // namespace v1
} // namespace sgl
