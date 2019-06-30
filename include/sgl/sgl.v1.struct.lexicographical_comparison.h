#pragma once

namespace sgl {
namespace v1 {

template<typename It0, typename It1>
struct lexicographical_comparison {
    bool operator()(const std::pair<It0, It0>& x, const std::pair<It1, It1>& y) const {
        return std::lexicographical_compare(x.first, x.second, y.first, y.second);
    }

    bool operator()(It0 f0, It0 l0, It1 f1, It1 l1) const {
        return std::lexicographical_compare(f0, l0, f1, l1);
    }
};


} // namespace v1
} // namespace sgl
