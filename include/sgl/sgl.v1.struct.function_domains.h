#pragma once

namespace sgl {
namespace v1 {
template<typename T>
struct function_domains;

template<typename R, typename... Args>
struct function_domains<R(Args...)> {
  // TODO fixme
  using codomain = R;
  using domain = std::tuple<Args...>;
};
} // namespace v1
} // namespace sgl
