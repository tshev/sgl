#pragma once

namespace sgl {
namespace v1 {
template<typename It0, typename F>
requires(
    sgl::v1::input_iterator<It0> && (sgl::v1::readable<It0> || sgl::v1::writable<It0>) &&
    sgl::v1::functional_procedure<F, SGLValueType(It0)>
)
void for_each(It0 first_0, It0 last_0, F function) {
  while (first_0 != last_0) {
    function(*first_0);
    ++first_0;
  }
}

template<typename It0, typename It1, typename F>
requires(
    sgl::v1::input_iterator<It0> && (sgl::v1::readable<It0> || sgl::v1::writable<It0>) &&
    sgl::v1::input_iterator<It1> && (sgl::v1::readable<It1> || sgl::v1::writable<It1>) &&
    sgl::v1::functional_procedure<F, SGLValueType(It0), SGLValueType(It1)>
)
void for_each(It0 first_0, It0 last_1, It1 first_1, F f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1);
    ++first_0;
    ++first_1;
  }
}

template<typename It0, typename It1, typename It2, typename F>
requires(
    sgl::v1::input_iterator<It0> && (sgl::v1::readable<It0> || sgl::v1::writable<It0>) &&
    sgl::v1::input_iterator<It1> && (sgl::v1::readable<It1> || sgl::v1::writable<It1>) &&
    sgl::v1::input_iterator<It2> && (sgl::v1::readable<It2> || sgl::v1::writable<It2>) &&
    sgl::v1::functional_procedure<F, SGLValueType(It0), SGLValueType(It1), SGLValueType(It2)>
)
void for_each(It0 first_0, It0 last_1, It1 first_1, It2 first_2, F f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1, *first_2);
    ++first_0;
    ++first_1;
    ++first_2;
  }
}

template<typename It0, typename It1, typename It2, typename It3, typename F>
requires(
    sgl::v1::input_iterator<It0> && (sgl::v1::readable<It0> || sgl::v1::writable<It0>) &&
    sgl::v1::input_iterator<It1> && (sgl::v1::readable<It1> || sgl::v1::writable<It1>) &&
    sgl::v1::input_iterator<It2> && (sgl::v1::readable<It2> || sgl::v1::writable<It2>) &&
    sgl::v1::input_iterator<It3> && (sgl::v1::readable<It3> || sgl::v1::writable<It3>) &&
    sgl::v1::functional_procedure<F, SGLValueType(It0), SGLValueType(It1), SGLValueType(It2), SGLValueType(It3)>
)
void for_each(It0 first_0, It0 last_1, It1 first_1, It2 first_2, It3 first_3, F f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1, *first_2, *first_3);
    ++first_0;
    ++first_1;
    ++first_2;
    ++first_3;
  }
}

template<typename It0, typename It1, typename It2, typename It3, typename It4, typename F>
requires(
    sgl::v1::input_iterator<It0> && (sgl::v1::readable<It0> || sgl::v1::writable<It0>) &&
    sgl::v1::input_iterator<It1> && (sgl::v1::readable<It1> || sgl::v1::writable<It1>) &&
    sgl::v1::input_iterator<It2> && (sgl::v1::readable<It2> || sgl::v1::writable<It2>) &&
    sgl::v1::input_iterator<It3> && (sgl::v1::readable<It3> || sgl::v1::writable<It3>) &&
    sgl::v1::input_iterator<It4> && (sgl::v1::readable<It4> || sgl::v1::writable<It4>) &&
    sgl::v1::functional_procedure<F, SGLValueType(It0), SGLValueType(It1), SGLValueType(It2), SGLValueType(It3), SGLValueType(It4)>
)
void for_each(It0 first_0, It0 last_1, It1 first_1, It2 first_2, It3 first_3, It4 first_4, F f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1, *first_2, *first_3, *first_4);
    ++first_0;
    ++first_1;
    ++first_2;
    ++first_3;
    ++first_4;
  }
}

template<typename It0, typename It1, typename It2, typename It3, typename It4, typename It5, typename F>
requires(
    sgl::v1::input_iterator<It0> && (sgl::v1::readable<It0> || sgl::v1::writable<It0>) &&
    sgl::v1::input_iterator<It1> && (sgl::v1::readable<It1> || sgl::v1::writable<It1>) &&
    sgl::v1::input_iterator<It2> && (sgl::v1::readable<It2> || sgl::v1::writable<It2>) &&
    sgl::v1::input_iterator<It3> && (sgl::v1::readable<It3> || sgl::v1::writable<It3>) &&
    sgl::v1::input_iterator<It4> && (sgl::v1::readable<It4> || sgl::v1::writable<It4>) &&
    sgl::v1::input_iterator<It5> && (sgl::v1::readable<It5> || sgl::v1::writable<It5>) &&
    sgl::v1::functional_procedure<F, SGLValueType(It0), SGLValueType(It1), SGLValueType(It2), SGLValueType(It3), SGLValueType(It4), SGLValueType(It5)>
)
void for_each(It0 first_0, It0 last_1, It1 first_1, It2 first_2, It3 first_3, It4 first_4, It5 first_5, F f) {
  while (first_0 != last_1) {
    f(*first_0, *first_1, *first_2, *first_3, *first_4, *first_5);
    ++first_0;
    ++first_1;
    ++first_2;
    ++first_3;
    ++first_4;
    ++first_5;
  }
}

} // namespace v1
} // namespace sgl
