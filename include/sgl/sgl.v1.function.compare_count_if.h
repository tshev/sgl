#pragma once
namespace sgl {
namespace v1 {

template<typename It, typename P, typename T, typename R>
inline
bool compare_count_if(It first, It last, P pred, T n, R r) {
    T count = 0;
    while (first != last) {
        if (pred(*first))  ++count;
        if (r(count, n)) return true;
    }
    return false;
}

template<typename It, typename P, typename T>
inline
bool compare_count_if(It first, It last, P pred, T n) {
    return sgl::v1::compare_count_if(first, last, pred, n, [](auto x, auto y) { return x < y; });
}


//sgl::v1::compare_count(first, last, is_ok, 10, std::less<int>());


}
}
