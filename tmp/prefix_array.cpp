#include <vector>
#include <iostream>
#include <cstring>
#include <numeric>
#include <algorithm>

template<typename S>
class suffix_array {
    typedef std::vector<S> container_type;
    typedef typename container_type::iterator iterator;

    size_t size_;
    container_type data;
public:
    template<typename It>
    suffix_array(It first, It last) : size_(std::distance(first, last)), data(6 * size_ + 256ul, S(0)) {
        size_t n =  size_;
        auto permutation = std::begin(data);
        auto counts = permutation + 256;
        auto cls = counts + n;
        auto cn = cls + n;
        auto pn = cn + n;

        size_t classes = 1;
        auto s = first;
        for (size_t i = 0; i < n; ++i) {
            ++counts[s[i]];
        }
        return;

        for (size_t i = 1ul; i < 256; ++i) {
            counts[i] += counts[i - 1ul];
        }

        for (size_t i = 0ul; i < n; ++i) {
            permutation[--counts[s[i]]] = i;
        }
        counts[permutation[0]] = 0;

        for (size_t i = 1; i < n; ++i) {
            if (s[permutation[i]] != s[permutation[i - 1]]) ++ classes;
            counts[permutation[i]] = classes - 1ul;
        }

        for (size_t h = 0; (1ul << h) < n; ++h) {
            for (size_t i = 0; i < n; ++i) {
                pn[i] = permutation[i] - (1 << h);
                if (pn[i] < 0) pn[i] += n;
            }
            std::fill(counts, counts + classes, 0);
            for (size_t i = 0; i < n; ++i) {
                ++counts[cls[permutation[i]]];
            }
            std::partial_sum(counts, counts + n, counts);
            size_t i = n;
            while (i-- > 0) {
                permutation[--counts[cn[pn[i]]]] = pn[i];
            }
            cn[permutation[0]] = 0;
            classes = 1ul;
            for (size_t i = 1; i < n; ++i) {
                size_t mid1 = (permutation[i] + S(S(1) << h)) % n;
                size_t mid2 = (permutation[i - 1] + S(S(1) << h)) % n;
                if (counts[permutation[i]] != counts[permutation[i - 1]] || counts[mid1] != counts[mid2]) {
                    ++classes;
                }
                cn[permutation[i]] = classes - 1;
            }
            std::copy(cn, cn + n, counts);
        }
        
       
    }


    auto permutations(size_t n) {
        auto first = std::begin(data);
        return std::make_pair(first, first + n);
    }

    auto permutations(size_t n) const {
        auto first = std::begin(data);
        return std::make_pair(first, first + n);
    }

    auto counts(size_t n) {
        auto first = std::begin(data);
        return std::make_pair(first + n, first + 2 * n);
    }

    auto counts(size_t n) const {
        auto first = std::begin(data);
        return std::make_pair(first + n, first + 2 * n);
    }

    auto eqcls(size_t n) {
        auto first = std::begin(data);
        return std::make_pair(first + 2 * n, first + 3 * n);
    }

    auto eqcls(size_t n) const {
        auto first = std::begin(data);
        return std::make_pair(first + 2 * n, first + 3 * n);
    }

    size_t size() const {
        return size_;
    }
};
int main() {
    const char* str = "abaab";
    suffix_array<int> sa(str, str + std::strlen(str));
    auto p = sa.permutations(sa.size());
    std::for_each(p.first, p.second, [](auto x) {
        std::cout << x << std::endl;
    });

}
