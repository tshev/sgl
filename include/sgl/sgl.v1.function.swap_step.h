#pragma once

namespace sgl {
namespace v1 {

template<typename Iterator>
inline
void swap_step(Iterator& x, Iterator& y) {
    using std::swap;
    swap(*x, *y);
    ++x;
    ++y;
}

template<typename Iterator0, typename Iterator1>
inline
void swap_step(std::pair<Iterator0, Iterator1>& x, std::pair<Iterator0, Iterator1>& y) {
    swap_step(x.first, y.first);
    swap_step(x.second, y.second);
}

} // namespace 
} // namespace sgl
