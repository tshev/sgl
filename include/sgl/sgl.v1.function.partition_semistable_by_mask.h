template<typename ForwardIterator0, typename ForwardIterator1>
inline
ForwardIterator0 partition_semistable_by_mask(ForwardIterator0 first, ForwardIterator0 last, ForwardIterator1 first_mask) {
    auto position = sgl::v1::find_by_mask(first, last, first_mask);
    first = position.first;
    ForwardIterator1 fast_mask = position.second;

    if (first == last) {
        return first;
    }

    ForwardIterator0 fast = first;
    sgl::v1::successor_inplace(fast);
    sgl::v1::successor_inplace(fast_mask);

    while (fast != last) {
        if (*fast_mask) {
            sgl::v1::successor_inplace(fast);
            sgl::v1::successor_inplace(fast_mask);
        } else {
            sgl::v1::swap_step(first, fast);
            sgl::v1::successor_inplace(fast_mask);
        }
    }
    return first;
}

