#pragma once
namespace sgl {
namespace v1 {

template<typename T, typename N>
class unordered_registry {
public:
    typedef T key_type;
    typedef N value_type;

private:
    std::unordered_map<key_type, value_type> mapping_;
    value_type max_index_ = 0;

public:
    value_type max_index() const {
        return max_index_;
    }

    bool empty() const {
        return mapping_.empty();
    }

    size_t size() const {
        return mapping_.size();
    }

    value_type push(const T& key) {
        auto pos = mapping_.insert({key, max_index_});
        if (pos.second) {
            ++max_index_;
        }
        return pos.first->second;
    }

    std::pair<value_type, bool> get(const T& key) const {
        auto pos = mapping_.find(key);
        if (pos == std::end(mapping_)) {
            return {value_type(), false};
        }
        return {pos->second, true};
    }

    auto begin() const {
        return mapping_.begin();
    }

    auto end() const {
        return mapping_.end();
    }

    template<typename It>
    std::pair<value_type, bool> operator()(It first, It last) const {
        return this->get(T(first, last));
    }

    template<typename Istream>
    friend
    inline
    Istream& operator>>(Istream& istream, unordered_registry& registry) {
        unordered_registry::key_type tmp;
        while (istream) {
            std::getline(istream, tmp);
            if (!tmp.empty())
            registry.push(tmp);
            tmp.clear();
        }
        return istream;
    }

    template<typename Ostream>
    friend
    inline
    Ostream& operator<<(Ostream& ostream, const unordered_registry& registry) {
        std::vector<std::pair<unordered_registry::key_type, N>> pairs;
        sgl::v1::copy(registry.begin(), registry.end(), std::back_inserter(pairs));
        std::sort(pairs.begin(), pairs.end(), [](const auto& x, const auto& y) { return x.second < y.second; });
        for (const auto& x : pairs) {
            ostream << x.first << '\n';
        }
        return ostream;
    }
};

} // namespace v1
} // namespace sgl
