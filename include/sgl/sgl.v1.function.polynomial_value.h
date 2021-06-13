#pragma once

namespace sgl {
namespace v1 {


template<typename It, typename T>
T polynomial_value(It first, It last, T value) {
	T result = 0;
	if (first == last) return 0;
	result = *first;
	++first;
	T multiplier = value;
	while (first != last) {
		result += *first * value;
		value *= multiplier;
		++first;
	}
	return result;
}

} // namespace v1
} // namespace sgl
