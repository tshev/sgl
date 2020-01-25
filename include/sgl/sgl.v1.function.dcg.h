#pragma once

namespace sgl {
namespace v1 {

template<typename InputIterator, typename T>
T dcg(InputIterator first, InputIterator last, T result) {
	if (first != last) {
		result += *first;
		++first;
	} else {
		return result;
	}
	T norm(3);
	while (first != last) {
		result += *first / std::log2(norm);
		++norm; // probably, non-optimal, but plus is free

		++first;
	}
	return result;
}

}
}
