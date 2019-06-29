#pragma once
namespace sgl {
namespace v1 {

template<typename Ostream, typename Tag>
Ostream& log(Ostream &out, Tag tag, const char *file_name) {
  out << tag.name << " " << __DATE__ << " "  << file_name << std::endl;
  return out;
}
/**
 * @brief pimpl - pointer to implementation interface
*/
template<typename T>
requires(FunctionalProcedure(T))
struct pimpl {
  typedef T value_type;
  typedef T* pointer;
  T* value;

  pimpl() {}

  // non-owner
  // Additional templatizing was suggested by Vlad Fatenko (@fatvlad)
  template<typename U, bool enable = std::is_base_of<T, U>::value>
  pimpl(U* value) : value(value) {
    static_assert(enable, "T is not a base class for U");
  }

  pimpl(const pimpl &x) = default;

  pimpl& operator=(const pimpl &x) {
    value = x.value;
    return *this;
  }

  friend
  inline
  bool operator==(const pimpl &x, const pimpl &y) {
    return x.value == y.value;
  }

  friend
  inline
  bool operator!=(const pimpl &x, const pimpl &y) {
    return !(x == y);
  }

  T& operator*() {
    return *value;
  }

  const T& operator*() const {
    return *value;
  }

  template<typename... Args>
  auto operator()(Args&& ...args)  {
    return value->operator()(std::forward<Args>(args)...);
  }

  template<typename... Args>
  auto operator()(Args&& ...args) const {
    return value->operator()(std::forward<Args>(args)...);
  }
};

template<typename T>
inline
pimpl<T> make_pimpl(T* value) {
  return pimpl<T>{value};
}

} // namespace v1
} // namespace sgl
