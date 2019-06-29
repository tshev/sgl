#pragma once
namespace sgl {
namespace v1 {

template<typename Iterator>
struct range {
    Iterator first;
    Iterator last;
    range() = default;
    range(const range&) = default;
};

} // namespace v1
} // namespace sgl
