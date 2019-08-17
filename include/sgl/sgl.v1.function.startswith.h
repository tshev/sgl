#pragma once
namespace sgl {
namespace v1 {
template<typename It0, typename It1>
inline
bool startswith(It0 first0, It0 last0, It1 first1, It1 last1) {
    auto [_, right] = sgl::v1::gcp(first0, last0, first1, last1);
    return right == last1;
}

}
}
