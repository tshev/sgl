namespace sgl {
namespace v1 {

SGLConcept(
template<typename I>
concept readable = requires(I x)  { &(*x); };
)

} // namespace v1
} // namespace sgl
