#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename I>
concept input_iterator = std::is_base_of<std::input_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value;
)

}
}
