#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename T>
T ndcg_exp(It first, It last, T result) {
    return sgl::v1::ndcg(first, last, result, sgl::v1::f::dcg_exp<T>());
}

} // namespace v1
} // namespace sgl
