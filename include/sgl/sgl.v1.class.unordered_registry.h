#pragma once
namespace sgl {
namespace v1 {

template<typename T, typename S>
class unordered_registry {
    std::unordered_map<T, S> mapping_;
    S max_index_ = 0;
public:
    S max_index() const {
        return max_index_;
    }

    bool empty() const {
        return mapping_.empty();
    }

    size_t size() const {
        return mapping_.size();
    }
   
    S push(const T& key) {
        auto pos = mapping_.insert({key, max_index_});
        if (pos.second) {
            ++max_index_;
        }
        return pos.first->second;
    }

    std::pair<S, bool> get(const T& key) const {
        auto pos = mapping_.find(key);
        if (pos == std::end(mapping_)) {
            return {S(), false};
        }
        return {pos->second, true};
    }

    auto begin() const {
        return mapping_.begin();
    }

    auto end() const {
        return mapping_.end();
    }
};

} // namespace v1
} // namespace sgl
