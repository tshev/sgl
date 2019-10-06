#pragma once

namespace sgl {
namespace v1 {


template<typename It0, typename It1, typename Projection>
It0 gauss_method_forward(It0 first, It0 middle, It0 last, It1 b, Projection proj) {
    typedef size_t size_type;
    size_type n = std::distance(first, middle);
    
    for (size_type i = 1; i < n; ++i) {
        auto first_current  = first;
        auto middle_current = middle;
        auto b_current = b;
        while (middle_current != last) {
            auto _middle_current = middle_current;
            sgl::v1::advance(middle_current, n);
            sgl::v1::advance(first_current, n);

            ++b_current;
            auto norm = proj(*first_current);
            if (norm != 0) {
                sgl::v1::for_each(first, middle, first_current, [proj, first, norm](auto& x, auto& r) {
                    proj(r) = (proj(r) / norm * proj(*first)) - proj(x);
                });
                *b_current = *b_current / norm * proj(*first) - proj(*b);
            }
        }
        sgl::v1::advance(first, n);
        ++first;
        sgl::v1::advance(middle, n);
        ++b;
    }
    return first;
}


template<typename It0, typename Projection>
It0 gauss_method_forward(It0 first, It0 middle, It0 last, Projection proj) {
    typedef size_t size_type;
    size_type n = std::distance(first, middle);
    
    for (size_type i = 1; i < n; ++i) {
        auto first_current  = first;
        auto middle_current = middle;
        while (middle_current != last) {
            auto _middle_current = middle_current;
            sgl::v1::advance(middle_current, n);
            sgl::v1::advance(first_current, n);

            auto norm = proj(*first_current);
            if (norm != 0) {
                sgl::v1::for_each(first, middle, first_current, [proj, first, norm](auto x, auto& r) {
                    proj(r) = (proj(r) / norm * proj(*first)) - proj(x);
                });
            }
        }
        sgl::v1::advance(first, n);
        ++first;
        sgl::v1::advance(middle, n);
        
    }
    return first;
}


template<typename It0, typename Projection>
inline
It0 gauss_method_forward(It0 first, It0 middle, It0 last) {
    typedef typename std::iterator_traits<It0>::value_type T;
    struct identity {
        T& operator()(T& x) const { return x; }
    };
    return sgl::v1::gauss_method_forward(first, middle, last, identity{});
}

} // namespace v1
} // namespace sgl
