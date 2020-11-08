#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename T, typename F>
T dcg(It first, It last, T result, F ndcg_term) {
    return sgl::v1::accumulate(first, last, sgl::v1::position<T>(2), result, ndcg_term, sgl::v1::f::plus<T>());
}


template<typename It, typename T, typename F, typename Projection>
T dcg(It first, It last, T result, F ndcg_term, Projection projection) {
    return sgl::v1::accumulate(first, last, sgl::v1::position<T>(2), result, [projection, ndcg_term](const auto& x, const auto& rank) {
        return ndcg_term(projection(x), rank);
    }, sgl::v1::f::plus<T>());
}


template<typename It, typename T>
T dcg(It first, It last, T result) {
    return sgl::v1::accumulate(first, last, sgl::v1::position<T>(2), result, sgl::v1::f::dcg<T>(), sgl::v1::f::plus<T>());
}

} // namespace v1
} // namespace sgl
