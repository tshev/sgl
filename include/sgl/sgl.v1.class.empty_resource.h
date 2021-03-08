#pragma once

namespace sgl {
namespace v1 {

struct empty_resource {
    empty_resource() = default;

    empty_resource(empty_resource&&) = default;

    empty_resource(const empty_resource&) = delete;

    empty_resource& operator=(const empty_resource&) = delete;

    empty_resource& operator=(empty_resource&&) = default;

    ~empty_resource() = default;
};

} // namespace v1
} // namespace sgl
