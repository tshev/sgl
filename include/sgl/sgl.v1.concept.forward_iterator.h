#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename I>
concept forward_iterator = std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value;
)

} // namespace v1
} // namespace sgl
