#pragma once
namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename OutputIterator>
inline
OutputIterator stringify_batches(ForwardIterator first, ForwardIterator last, OutputIterator out) {
    while (first != last) {
        auto [data, data_size] = *first;
        out = sgl::v1::ubase10(data_size, out);
        *out = ' ';
        ++out;
        out = std::copy(data, data + data_size, out);
        ++first;
    }
    return out; 
}


}
}
