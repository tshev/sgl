#pragma once
namespace sgl {
namespace v1 {

template<typename RandomAccessIterator, typename F>
inline
void decode_batches(RandomAccessIterator first, RandomAccessIterator last, F f) {
    while (first != last) {
        uint64_t size;
        auto m = sgl::v1::parse_uint(first, last, &size);
        if (m == first) { return; }
        ++m;
        if (m == last) { return; }
        if (size > last - m) { return; }
        f(m, m + size);
        first = m + size;
    }
}

}
}
