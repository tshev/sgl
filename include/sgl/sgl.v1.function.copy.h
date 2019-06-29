#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename O>
inline
requires(ForwardIterator(It) && ForwardIterator(O))
O copy(It first, It last, O o) {
    return std::copy(first, last, o);
}

} // namespace v1
} // namespace sgl
