#pragma once

namespace sgl {
namespace v1 {

#if __cplusplus > 201703L

template<typename I>
concept forward_iterator = iterator(I) && std::is_base_of<std::forward_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value;

#endif

} // namespace v1
} // namespace sgl
