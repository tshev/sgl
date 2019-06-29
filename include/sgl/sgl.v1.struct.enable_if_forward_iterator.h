#pragma once

namespace sgl {
namespace v1 {

template<typename Iterator, typename T = void>
struct enable_if_forward_iterator {
    typedef typename std::enable_if<
        std::is_base_of<typename std::iterator_traits<Iterator>::iterator_category, std::forward_iterator_tag>::value,
        T
    >::type type;
};


} // namespace v1
} // namespace sgl
