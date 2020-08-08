#pragma once

namespace sgl {
namespace v1 {

SGLConcept(
template<typename I>
concept random_access_iterator_tag = std::is_base_of<std::random_access_iterator_tag, typename std::iterator_traits<I>::iterator_category>::value;
)

}
}
