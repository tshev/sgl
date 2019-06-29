#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
void mean_var(ForwardIterator first, ForwardIterator last, T val) {
    auto n = std::distance(first, last);
    T mean = sgl::v1::accumulate(first, last, val) / n;
    return sgl:v1::accumulate(first, last, val, sgl::v1::reducer::square_deviation(mean)) / n;
}

} // namespace v1
} // namespace sgl
