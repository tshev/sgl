#pragma once

namespace sgl {
namespace v1 {

template<typename T>
struct tuple_size;

template<typename... Args>
struct tuple_size<std::tuple<Args...>> {
	static constexpr size_t value = sizeof...(Args);
};

} // namespace v1
} // namespace sgl
