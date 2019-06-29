// TODO IMPLEMENT ME
namespace sgl {
namespace v1 {
template<typename T>
class quadtree {
  struct node_t;
  typedef node_t* link_type;

  struct node_t {
    bounding_box<T> bounding_box;

    union {
      struct {
        link_type links[4];
      };

      struct {
        link_type l0;
        link_type l1;
        link_type l2;
        link_type l3;
      };
    };
  }:
};
} // namespace v1
} // namespace sgl
