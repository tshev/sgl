#pragma once
namespace sgl {
namespace v1 {
// TODO: FINISHME

struct allocator_std_tag {};
struct allocator_std_reallocatable_tag {};

struct allocator_experimental_tag {};
struct allocator_experimental_reallocatable_tag {};


template<typename T>
struct allocator_traits {
};

template<typename Iterator>
struct allocator_tag_t = typename allocator_traits<Iterator>::allocator_category;

} // namespace v1
} // namespace sgl
