#pragma once

namespace sgl {
namespace v1 {

template<typename Iterator>
inline
void successor_inplace(Iterator& x) {
    ++x;
}


template<typename Iterator0, typename Iterator1>
inline
void successor_inplace(std::pair<Iterator0, Iterator1>& x) {
    ++x.first;
    ++x.second;
}

} // namespace v1
} // namespace sgl
