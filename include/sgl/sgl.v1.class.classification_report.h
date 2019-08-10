#pragma once
namespace sgl {
namespace v1 {

template<typename T = double>
class classification_report {
    std::vector<T> data;

public:
    template<typename ForwardIterator0, typename ForwardIterator1>
    classification_report(size_t n, ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1) : data(3 * n, 0.0)  {
        auto first_tp = std::begin(data);
        auto last_tp = first_tp + n;
        auto first_fn = last_tp + n;
        sgl::v1::precision_and_recall(f0, l0, f1, first_tp, last_tp, last_tp, first_fn);
    }

    template<typename ForwardIterator0, typename ForwardIterator1>
    classification_report(ForwardIterator0 f0, ForwardIterator0 l0, ForwardIterator1 f1) : classification_report(sgl::v1::count_classes(f0, l0), f0, l0, f1) {}

    size_t count() const {
        return data.size() / 3ul;
    }

    auto precisions() const {
        size_t n = count();
        return std::make_pair(data.begin(), data.begin() + n);
    }

    auto precision() const {
        auto precisions_range = precisions();
        return std::accumulate(precisions_range.first, precisions_range.second, 0.0) / T(count());
    }

    auto recalls() const {
        size_t n = count();
        return std::make_pair(data.begin() + n, data.begin() + 2 * n);
    }

    auto recall() const {
        auto precisions_range = recalls();
        return std::accumulate(precisions_range.first, precisions_range.second, 0.0) / T(count());
    }

};


} // namespace v1
} // namespace sgl
