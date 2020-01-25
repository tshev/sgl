#pragma once
namespace sgl {
namespace v1 {

template<typename T>
inline
T heaps_law(T n, T k, T b) {
    // n \in [10, 100] &  b \in [0.4, 0.6] for English texts
    // capacity = heaps_law(n, 10, 0.6);
    return k * std::pow(n, b);
}

}  // namespace v1
}  // namespace sgl
