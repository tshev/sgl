#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T, typename Func>
void for_each_split(ForwardIterator first, ForwardIterator last, const T& value, Func func) {
    while (first != last) {
        ForwardIterator next = sgl::v1::find(first, last, value);
        func(first, next);
        first = next;
        if (first != last) {
            ++first;
        }
    }
}

}
}
