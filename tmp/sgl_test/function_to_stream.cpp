namespace sgl {
template<typename Ostream>
void to_stream(Ostream& ostream) {}

template<typename Ostream, typename T>
void to_stream(Ostream& ostream, const T& x) {
  ostream << x;
}

template<typename Ostream, typename T, typename... Args>
void to_stream(Ostream& ostream, const T& x, const Args&... args) {
  ostream << x;
  to_stream(ostream, args...);
}
} // namespace sgl
