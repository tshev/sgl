#pragma once

namespace sgl {
namespace v1 {

template<typename It, typename Pred>
inline
std::pair<bool, bool> all_any(It first, It last, Pred pred) {
    bool all_ = true;
    bool any_ = false;
    while (first != last) {
        bool result = pred(*first);
        ++first;
        all_ = all_ && result;
        any_ = any_ || result;
    }
    // TOOD: return sgl::v1::bit_field<8>(all_, any_);
    return {all_, any_};
}

} // namespace v1
} // namespace sgl
