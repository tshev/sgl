#pragma once
namespace sgl {
namespace v1 {
template<typename T, typename A = std::allocator<T>>
using queue_fast = sgl::queue<T, A, false>;
} // namespace v1
} // namespace sgl
