#pragma once
namespace sgl {
namespace v1 {


// Least Recently Inserted
template<typename K, typename V>
class lri_cache {
    sgl::v1::linked_list<K, V> list_;
    std::unordered_map<K, V> list_;
};

} // namespace v1
} // namespace sgl
