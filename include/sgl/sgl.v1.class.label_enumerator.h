#pragma once

namespace sgl {
namespace v1 {

template<typename T, typename S>
class label_enumerator {
    std::unordered_map<T, S> labels;
    S current_label_id = 0;

public:
    label_enumerator() = default;
    label_enumerator(S s) : current_label_id(s) {}
    label_enumerator(const label_enumerator&) = default;
    label_enumerator(label_enumerator&&) = default;

    S get(const T& x) {
        auto pos = labels.find(x);
        if (pos == std::end(labels)) {
            labels.insert(pos, {x, current_label_id});
            size_t result = current_label_id;
            ++current_label_id;
            return result;
        }
        return pos->second;
    }

    auto begin() {
        return labels.begin();
    }

    auto begin() const {
        return labels.begin();
    }

    auto end() {
        return labels.end();
    }

    auto end() const {
        return labels.end();
    }

    S next_label_id() const {
        return current_label_id;
    }
};

} // namespace v1
} // namespace sgl
