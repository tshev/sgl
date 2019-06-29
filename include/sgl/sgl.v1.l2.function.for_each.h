#pragma once
namespace sgl {
namespace v1 {
namespace l2 {

template<typename L2ForwardIterator, typename Function>
void for_each(L2ForwardIterator first, L2ForwardIterator last, Function f) {
    while (first != last) {
        auto first0 = sgl::v1::begin(first);
        auto last0 = sgl::v1::end(first);
        while (first0 != last0) {
            f(*first0);
            ++first0;
        }
        ++first;
    }

}

}
} //
} // namespace sgl
