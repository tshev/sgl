namespace sgl {
namespace v1 {

template<typename I, typename T>
concept writable = requires(I it, T&& value) {
    *it = std::forward<T>(value);
};

} // namespace v1
} // namespace sgl
