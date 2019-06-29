namespace sgl {
namespace v1 {

template<typename BidirectionalIterator>
void linear_insert(BidirectionalIterator first, BidirectionalIterator current) {
    typedef typename std::iterator_traits<I>::value_type T;

    T value = std::move(*current);
    BidirectionalIterator fast = current;

    while (first != current && value < *(--fast)) {
        *current = std::move(*fast);
        --current;
    }

    *current = std::move(value);
}


template<typename BidirectionalIterator>
void insertion_sort(BidirectionalIterator first, BidirectionalIterator last) {
    if (first == last) {
        return;
    }

    auto current = first;
    ++current;

    while (current != last) {
        linear_insert(first, current);
        ++current;
    }
}

} // namespace v1
} // namespace sgl
