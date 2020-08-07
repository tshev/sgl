#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename T>
T dcg_exp(It first, It last, T result) {
    return sgl::v1::dcg(first, last, result, sgl::v1::f::dcg_exp<T>());
}

}
}

