#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename I>
concept bidirectional_iterator_tag = std::is_base_of<std::bidirectional_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value;
)

}
}
