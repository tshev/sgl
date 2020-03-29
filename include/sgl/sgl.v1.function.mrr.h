#pragma once

namespace sgl {
namespace v1 {

template<typename ForwardIterator, typename T>
T mrr(ForwardIterator first, ForwardIterator last, const std::iterator_traits<ForwardIterator>::value_type& threshold) {
	ForwardIterator middle = std::find_if(first, last, [threshold](auto x) { return x > threshold; });
	T distance(std::distance(first, middle));
	++distance;
	return T(1) / distance;
}

template<typename ForwardIterator, typename Predicate>
T mrr(ForwardIterator first, ForwardIterator last, Predicate pred) {
	ForwardIterator middle = std::find_if(first, last, pred);
	T distance(std::distance(first, middle));
	++distance;
	return T(1) / distance;
}


}
}
