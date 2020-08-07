#pragma once
namespace sgl {
namespace v1 {

template<typename It0, typename It1, typename OutputIterator>
typename std::enable_if<std::is_floating_point< typename std::iterator_traits<It0>::value_type >::value, OutputIterator>::type
ndcgs(It0 first0, It0 last0, It1 first1, OutputIterator out) {
    return sgl::v1::transform_subgroups(first0, last0, first1, out, [](const auto& _x0, const auto& x1, const auto& _y0, const auto& y1) {
        return x1 == y1;
    }, [](auto first0, auto last0, auto _first1) {
        typedef typename std::iterator_traits<It0>::value_type T;
        return sgl::v1::ndcg(first0, last0, T(0.0f));
    });
}


template<typename It0, typename OutputIterator, typename F, typename Projection, typename Projection1>
typename std::enable_if<std::is_invocable<Projection, typename std::iterator_traits<It0>::value_type>::value, OutputIterator>::type
ndcgs(It0 first0, It0 last0, OutputIterator out, F ndcg_term, Projection projection, Projection1 projection1) {
    typedef typename std::iterator_traits<OutputIterator>::value_type T;
    return sgl::v1::transform_subgroups(first0, last0, out, [projection1](const auto& x, const auto& y) {
        return projection1(x) == projection1(y);
    }, [projection, ndcg_term](auto first0, auto last0) {
        return sgl::v1::ndcg(first0, last0, T(0), ndcg_term, projection);
    });
}


template<typename It0, typename OutputIterator, typename F>
OutputIterator ndcgs(It0 first0, It0 last0, OutputIterator out, F ndcg_term) {
    return sgl::v1::ndcgs(first0, last0, out, ndcg_term, [](const auto& x) {
        const auto& [rel, _group_id] = x;
        return rel;
    }, [](const auto& x) {
        const auto& [_rel, group_id] = x;
        return group_id;
    });
}


template<typename It0, typename OutputIterator>
OutputIterator ndcgs(It0 first0, It0 last0, OutputIterator out) {
    return sgl::v1::ndcgs(first0, last0, out, sgl::v1::f::dcg<typename std::iterator_traits<OutputIterator>::value_type>(), [](const auto& x) {
        const auto& [rel, _group_id] = x;
        return rel;
    }, [](const auto& x) {
        const auto& [_rel, group_id] = x;
        return group_id;
    });
}

} // namespace v1
} // namespace sgl 
