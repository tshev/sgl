#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename T, typename F, typename Projection>
T ndcg(It first, It last, T result, F ndcg_term, Projection projection) {
    T dcg = sgl::v1::dcg(first, last, result, ndcg_term, projection);
    std::sort(first, last, [projection](const auto& x, const auto& y) { return projection(y) < projection(x); });
    T idcg = sgl::v1::dcg(first, last, result, ndcg_term, projection);
    return dcg / idcg;
}


template<typename It, typename T, typename F>
T ndcg(It first, It last, T result, F ndcg_term) {
    return ndcg(first, last, result, [](const auto& value) {
        return value;
    });
}


template<typename It, typename T>
inline
T ndcg(It first, It last, T result) {
    return sgl::v1::ndcg(first, last, result, sgl::v1::f::dcg<T>());
}

} // namespace v1
} // namespace sgl
