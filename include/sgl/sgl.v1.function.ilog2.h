#pragma once
namespace sgl {
namespace v1 {

template<typename T>
struct _ilog2 {
    T operator()(const T& value) {
        //return sgl::v1::ilog(value, 2);
        return std::log2(value);
    }
};

template<>
struct _ilog2<unsigned int> {
    typedef unsigned int T;
    T operator()(T x) {
        return T(int(sizeof(T)) * 8 - 1 - __builtin_clz(x));
    }
};

template<>
struct _ilog2<int> {
    typedef int T;
    T operator()(T x) {
        return T(int(sizeof(T)) * 8 - 1 - __builtin_clz(x));
    }
};



template<>
struct _ilog2<unsigned long> {
    typedef unsigned long T;
    T operator()(T x) {
        return T(int(sizeof(T)) * 8 - 1 - __builtin_clzl(x));
    }
};

template<>
struct _ilog2<long> {
    typedef long T;
    T operator()(T x) {
        return T(int(sizeof(T)) * 8 - 1 - __builtin_clzl(x));
    }
};

template<>
struct _ilog2<unsigned long long> {
    typedef unsigned long long T;
    T operator()(T x) {
        return T(int(sizeof(T)) * 8 - 1 - __builtin_clzll(x));
    }
};


template<>
struct _ilog2<long long> {
    typedef long long T;
    T operator()(T x) {
        return T(int(sizeof(T)) * 8 - 1 - __builtin_clzll(x));
    }
};


template <typename N>
inline
N ilog2(N value) {
    return sgl::v1::_ilog2<N>()(value);
}

} // namespace v1
} // namespace sgl
