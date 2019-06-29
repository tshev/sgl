namespace sgl {
namespace v1 {
void tolower(std::string &phrase) {
  sgl::v1::for_each(std::begin(phrase), std::end(phrase), [](auto &x) { x = std::tolower(x); });
}
} // namespace v1
} // namespace sgl
