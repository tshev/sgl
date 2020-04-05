#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename Integer>
inline
Integer stringification_size(ForwardIterator first, ForwardIterator last, Integer result) {
    static_assert(std::is_same<Integer, typename decltype(*first)::second_type>::value, "Say no to implicit convertions");
    return sgl::v1::accumulate(first, last, result, [](auto r, const auto& x) {
        return r + sgl::v1::count_digits(x.second, Integer(10) ) + Integer(1) + x.second;
    });
}

} // namespace v1
} // namespace sgl
