#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator0, typename ForwardIterator1, typename RandomAccessIterator0, typename RandomAccessIterator1, typename RandomAccessIterator2>
ForwardIterator1 precision_and_recall(ForwardIterator0 first_expected,
                          ForwardIterator0 last_expected,
                          ForwardIterator1 first_predicted,
                          RandomAccessIterator0 first_tp,
                          RandomAccessIterator0 last_tp,
                          RandomAccessIterator1 first_fp,
                          RandomAccessIterator2 first_fn) {
    ForwardIterator1 result = sgl::v1::metrics_tp_fp_fn(first_expected, last_expected, first_predicted, first_tp, first_fp, first_fn);

    while (first_tp != last_tp) {
        auto tp = *first_tp;
        auto fp = *first_fp;
        auto fn = *first_fn;

        *first_tp = tp / (tp + fp);
        *first_fp = tp / (tp + fn);

        ++first_tp;
        ++first_fp;
        ++first_fn;
    }
    return result;
}


} // namespace v1
} // namespace sgl
