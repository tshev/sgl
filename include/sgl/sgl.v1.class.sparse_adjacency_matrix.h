#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct sprase_adjency_matrix {
    sgl::v1::array<std::pair<T, T>> posting_list;
    sgl::v1::array<T> cols;

    sprase_adjency_matrix() = default;

    sprase_adjency_matrix(size_t n_rows) : posting_list {
        posting_list.reserve(n_rows);
    }

    void reserve(size_t n) {
        cols.reserve(n);
    }
    
    void emplace_back(T i, T j) {
        if (posting_list.size() <= i) {
            if (!posting_list.empty() && posting_list.capacity() <= i) {
                posting_list.reserve(posting_list.capacity() * 2ull);
            }
            posting_list.resize(i + 1);
            posting_list[i].first = cols.size();
        }
        ++posting_list[i].second;
        cols.push_back(j); 
    }

    template<typename It>
    void emplace_back(T i, It first, It last) {
        if (posting_list.size() <= i) {
            posting_list.resize(i + 1);
            posting_list[i].first = cols.size();
        }
        std::for_each(first, last, [this, i](T j) {
            ++posting_list[i].second;
            cols.push_back(j); 
        });
    }

    auto find(T i) const {
        auto coordindates = posting_list[i];
        auto first = cols.begin() + coordindates.first;
        auto last = first + coordindates.second;
        return std::make_pair(first, last);
    }

    template<typename O>
    O copy(T i, O out) const {
        auto [first, last] = find(i);
        return std::copy(first, last, out);
    }
};

} // namespace v1
} // namespace sgl
