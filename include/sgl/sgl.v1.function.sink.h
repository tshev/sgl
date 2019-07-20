#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator>
auto& sink(ForwardIterator x) {
    return *x;
}

} // namespace v1
} // namespace sgl
