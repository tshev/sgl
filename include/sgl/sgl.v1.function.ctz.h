#pragma onace

namespace sgl {
namespace v1 {

template<typename T>
struct _ctz {
    int operator()(T m) const {
        int result = 0;
        while (even(m)) { m >>= 1; ++result; }
        return result;
    }
};

template<>
struct _ctz<unsigned int> {
    int operator()(unsigned int value) const noexcept {
        return __builtin_ctz(value);
    }
};

template<>
struct _ctz<int> {
    int operator()(int value) const noexcept {
        return __builtin_ctz(static_cast<unsigned int>(value));
    }
};


template<>
struct _ctz<unsigned long> {
    int operator()(unsigned long  value) const noexcept {
        return __builtin_ctzl(value);
    }
};

template<>
struct _ctz<long> {
    int operator()(long value) const noexcept {
        return __builtin_ctzl(static_cast<unsigned long>(value));
    }
};


template<>
struct _ctz<unsigned long long> {
    int operator()(unsigned long long value) const noexcept {
        return __builtin_ctzl(value);
    }
};

template<>
struct _ctz<long long> {
    int operator()(long long value) const noexcept {
        return __builtin_ctzl(static_cast<unsigned long long>(value));
    }
};

template<typename T>
int ctz(const T& value) {
    return sgl::v1::_ctz<T>{}(value);
}

}
}
