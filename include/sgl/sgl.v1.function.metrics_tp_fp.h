#pragma once
namespace sgl {
namespace v1 {


template<typename ForwardIterator0, typename ForwardIterator1, typename RandomAccessIterator0, typename RandomAccessIterator1, typename RandomAccessIterator2>
inline
ForwardIterator1 metrics_tp_fp_fn(ForwardIterator0 first_true,
                                  ForwardIterator0 last_true,
                                  ForwardIterator1 first_predicted,
                                  RandomAccessIterator0 first_tp,
                                  RandomAccessIterator1 first_fp) {

    while (first_true != last_true) {
        if (*first_true == *first_predicted) {
            ++first_tp[*first_predicted];
        } else {
            ++first_fp[*first_predicted];
        }

        ++first_true;
        ++first_predicted;
    }
    return first_predicted;
}


} // namespace v1
} // namespace sgl
