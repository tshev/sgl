#pragma once
#include "./common.h"
namespace sgl {
namespace v1 {
namespace transfomation {
template<typename ForwardIterator, typename T, typename OutputIterator>
OutputIterator cumulate_one(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                        OutputIterator out, T identity_element) {
  auto current_value = identity_element;
  for (ForwardIterator it = first; it != middle; ++it) {
    current_value = current_value + *it;
  }
  *out = std::move(current_value);
  ++out;

  while (middle != last) {
    ++first;
    ++middle;
    auto current_value = identity_element;
    for (ForwardIterator it = first; it != middle; ++it) {
      current_value = current_value + *it;
    }
    *out = std::move(current_value);
    ++out;
  }
  return out;
}

template<typename ForwardIterator, typename T, typename OutputIterator, typename Operation>
OutputIterator cumulate_one(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                            OutputIterator out,  T identity_element, Operation operation) {
  auto current_value = identity_element;
  for (ForwardIterator it = first; it != middle; ++it) {
    current_value = operation(current_value, *it);
  }
  *out = std::move(current_value);
  ++out;

  while (middle != last) {
    ++first;
    ++middle;
    auto current_value = identity_element;
    for (ForwardIterator it = first; it != middle; ++it) {
      current_value = operation(current_value, *it);
    }
    *out = std::move(current_value);
    ++out;
  }
  return out;
}

template<typename ForwardIterator, typename T, typename OutputIterator, typename Operation, typename Projection>
OutputIterator cumulate_one(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                            OutputIterator out,  T identity_element, Operation operation, Projection projection) {
  auto current_value = identity_element;
  for (ForwardIterator it = first; it != middle; ++it) {
    current_value = operation(current_value, projection(*it));
  }
  *out = std::move(current_value);
  ++out;

  while (middle != last) {
    ++first;
    ++middle;
    auto current_value = identity_element;
    for (ForwardIterator it = first; it != middle; ++it) {
      current_value = operation(current_value, projection(*it));
    }
    *out = std::move(current_value);
    ++out;
  }
  return out;
}

} // namespace transfomation

namespace action {
template<typename ForwardIterator, typename T, typename OutputIterator, typename Action>
OutputIterator cumulate_one(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                            OutputIterator out,  T identity_element, Action action) {
  auto current_value = identity_element;
  for (ForwardIterator it = first; it != middle; ++it) {
    action(current_value, *it);
  }
  *out = std::move(current_value);
  ++out;

  while (middle != last) {
    ++middle;
    ++first;
    auto current_value = identity_element;
    for (ForwardIterator it = first; it != middle; ++it) {
      action(current_value, *it);
    }
    *out = std::move(current_value);
    ++out;
  }
  return out;
}

template<typename ForwardIterator, typename T, typename OutputIterator, typename Action, typename Projection>
OutputIterator cumulate_one(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                            OutputIterator out,  T identity_element, Action action, Projection projection) {

  auto current_value = identity_element;
  for (ForwardIterator it = first; it != middle; ++it) {
    action(current_value, projection(*it));
  }
  *out = std::move(current_value);
  ++out;

  while (middle != last) {
    ++middle;
    ++first;
    auto current_value = identity_element;
    for (ForwardIterator it = first; it != middle; ++it) {
      action(current_value, projection(*it));
    }
    *out = std::move(current_value);
    ++out;
  }
  return out;

}
} // namespace action
} // namespace v1
} // namespace sgl
