#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename I>
concept iterator = std::is_base_of<std::input_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value ||
                   std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value ||
                   std::is_base_of<std::output_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value ||
                   std::is_base_of<std::bidirectional_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value ||
                   std::is_base_of<std::random_access_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value;
)

} // namespace v1
} // namespace sgl
