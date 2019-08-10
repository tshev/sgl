#pragma once
namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename ForwardIterator1, typename RandomAccessIterator0, typename RandomAccessIterator1, typename RandomAccessIterator2>
inline
ForwardIterator1 metrics_tp_fp_fn(ForwardIterator0 first_expected,
                                  ForwardIterator0 last_expected,
                                  ForwardIterator1 first_predicted,
                                  RandomAccessIterator0 first_tp,
                                  RandomAccessIterator1 first_fp,
                                  RandomAccessIterator2 first_fn) {

    while (first_expected != last_expected) {
        if (*first_expected == *first_predicted) {
            ++first_tp[*first_predicted];
        } else {
            ++first_fp[*first_predicted];
            ++first_fn[*first_expected];
        }

        ++first_expected;
        ++first_predicted;
    }
    return first_predicted;
}


} // namespace v1
} // namespace sgl
