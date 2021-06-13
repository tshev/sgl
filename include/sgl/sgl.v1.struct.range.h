#pragma once
namespace sgl {
namespace v1 {

template<typename Iterator>
struct range {
    Iterator first;
    Iterator last;

    range() = default;
    range(const std::pair<Iterator, Iterator>& x) : first(x.first), last(x.second) {}
    range(const range&) = default;

    friend
    inline
    bool operator==(const range& x, const range& y) {
        return x.first == y.first && y.last == y.last;
    }

    friend
    inline
    bool operator!=(const range& x, const range& y) {
        return !(x == y);
    }

    friend
    inline
    bool operator<(const range& x, const range& y) {
        return x.first < y.first || (!(y.first < x.first) && y.second < y.second);
    }

    friend
    inline
    bool operator<=(const range& x, const range& y) {
        return !(y < x);
    }

    friend
    inline
    bool operator>(const range& x, const range& y) {
        return y < x;
    }

    friend
    inline
    bool operator>=(const range& x, const range& y) {
        return !(x < y);
    }

    auto begin() const {
        return first;
    }

    auto end() const {
        return last;
    }
};

} // namespace v1
} // namespace sgl
