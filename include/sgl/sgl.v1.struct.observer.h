#pragma once

namespace sgl {
namespace v1 {

template<typename F, typename... O>
// requires(FunctionalProcedure(F) && FunctionalProcedure(O) && (Arity(O) = 0 || Arity(O) == 1))
struct observer {
	F function;
	std::tuple<O...> observers;

	template<typename... Args, typename std::enable_if<!std::is_same<void, typename std::result_of<F(Args&& ...)>::type>::value, bool>::type = false>
	auto operator()(Args&& ...args) const {
		auto result = function(std::forward<Args>(args)...);
		sgl::v1::for_each_in_tuple(observers, [&](auto& f) {
			f(result);
		});
		return result;
	}

	template<typename... Args, typename std::enable_if<!std::is_same<void, typename std::result_of<F(Args&& ...)>::type>::value, bool>::type = false>
	auto operator()(Args&& ...args) {
		auto result = function(std::forward<Args>(args)...);
		sgl::v1::for_each_in_tuple(observers, [&](auto& f) {
			f(result);
		});
		return result;
	}

	template<typename... Args, typename std::enable_if<std::is_same<void, typename std::result_of<F(Args&& ...)>::type>::value, bool>::type = true>
	void operator()(Args&& ...args) const {
		function(std::forward<Args>(args)...);
		sgl::v1::for_each_in_tuple(observers, [&](auto& f) {
			f();
		});
	}

	template<typename... Args, typename std::enable_if<std::is_same<void, typename std::result_of<F(Args&& ...)>::type>::value, bool>::type = true>
	void operator()(Args&& ...args) {
		function(std::forward<Args>(args)...);
		sgl::v1::for_each_in_tuple(observers, [&](auto& f) {
			f();
		});
	}

	template<size_t i>
	auto& get() {
		return std::get<i>(observers);
	}

	template<size_t i>
	const auto& get() const {
		return std::get<i>(observers);
	}

	template<int i>
	auto& get() {
		return std::get<i>(observers);
	}

	template<int i>
	const auto& get() const {
		return std::get<i>(observers);
	}
};
} // namespace v1
} // namespace sgl
