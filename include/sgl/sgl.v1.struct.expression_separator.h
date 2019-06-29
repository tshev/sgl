#pragma once

namespace sgl {
namespace v1 {
struct expression_separator {
    bool operator()(char x) const {
        return x == '"' || x == '\'' || x == ' ' || x == '=';
    }
};
} // namespace v1
} // namespace sgl
