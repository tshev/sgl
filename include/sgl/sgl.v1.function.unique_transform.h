namespace sgl {
namespace v1 {
template<typename ForwardIterator, typename OutputIterator, typename BinaryPredicate, typename Transformation>
OutputIterator unique_transform(ForwardIterator first, ForwardIterator last, OutputIterator out, BinaryPredicate predicate, Transformation f) {
  if (first == last) {
    return out;
  }
  auto fast = first;
  ++fast;
  *out = f(*first);
  ++out;
  while (fast != last) {
    if (!predicate(*first, *fast)) {
      first = fast;
      *out = f(*first);
      ++out;
    }
    ++fast;
  }
  return out;
}
} // namespace v1
} // namespace sgl
