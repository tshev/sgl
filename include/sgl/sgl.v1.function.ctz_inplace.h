#pragma onace

namespace sgl {
namespace v1 {

template<typename T>
struct _ctz_inplace {
    int operator()(T& m) const {
        int result = 0;
        while (even(m)) {
            m >>= 1;
            ++result;
        }
        return result;
    }
};

template<>
struct _ctz_inplace<unsigned int> {
    int operator()(unsigned int& value) const noexcept {
        int result = __builtin_ctz(value);
        value >>= result;
        return result;
    }
};

template<>
struct _ctz_inplace<int> {
    int operator()(int& value) const noexcept {
        int result = __builtin_ctz(static_cast<unsigned int>(value));
        value >>= result;
        return result;
    }
};

template<>
struct _ctz_inplace<unsigned long> {
    int operator()(unsigned long& value) const noexcept {
        int result = __builtin_ctzl(value);
        value >>= result;
        return result;
    }
};

template<>
struct _ctz_inplace<long> {
    int operator()(long& value) const noexcept {
        int result = __builtin_ctzl(static_cast<unsigned long>(value));
        value >>= result;
        return result;
    }
};

template<>
struct _ctz_inplace<unsigned long long> {
    int operator()(unsigned long long& value) const noexcept {
        int result = __builtin_ctzl(value);
        value >>= result;
        return result;
    }
};

template<>
struct _ctz_inplace<long long> {
    int operator()(long long& value) const noexcept {
        int result = __builtin_ctzl(static_cast<unsigned long long>(value));
        value >>= result;
        return result;
    }
};

template<typename T>
inline
int ctz_inplace(T& value) {
    return sgl::v1::_ctz_inplace<T>{}(value);
}

} // namespace v1
} // namespace sgl
