#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename Out, typename T>
Out sort_delimited_subranges(It first, It last, Out out, const T& delimiter) {
    std::vector<std::pair<It, It>> positions;
    while (first != last) {
        auto f0 = first;
        first = std::find(first, last, delimiter);
        if (first != last) { ++first; }
        else { break; }
        positions.emplace_back(f0, first);
    }

    std::sort(std::begin(positions), std::end(positions), [](const auto& a, const auto& b) {
        return std::lexicographical_compare(a.first, a.second, b.first, b.second);
    });
    
    auto f1 = std::begin(positions);
    auto l1 = std::end(positions);
    while (f1 != l1) {
        out = std::copy(f1->first, f1->second, out);
        ++f1;
    }
    return out;
}


template<typename It, typename Out, typename T, typename BinaryPredicate>
Out sort_delimited_subranges(It first, It last, Out out, const T& delimiter, BinaryPredicate pred) {
    std::vector<std::pair<It, It>> positions;
    while (first != last) {
        auto f0 = first;
        first = std::find(first, last, delimiter);
        if (first != last) { ++first; }
        else { break; }
        positions.emplace_back(f0, first);
    }

    std::sort(std::begin(positions), std::end(positions), pred);
    
    auto f1 = std::begin(positions);
    auto l1 = std::end(positions);
    while (f1 != l1) {
        out = std::copy(f1->first, f1->second, out);
        ++f1;
    }
    return out;
}


}
}
