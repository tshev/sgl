#pragma once

namespace sgl {
namespace v1 {

template<typename OutputIterator>
auto& source(ForwardIterator x) {
    return *x;
}

} // namespace v1
} // namespace sgl
