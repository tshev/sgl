#pragma onace

namespace sgl {
namespace v1 {

SGLConcept(
template<typename T>
concept resource = std::is_default_constructible<T>::value && std::is_move_constructible<T>::value && std::is_destructible<T>::value;
)

}
}
