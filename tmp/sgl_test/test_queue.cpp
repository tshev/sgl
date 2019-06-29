#include <sgl/sgl.h>
#include <sgl/class_queue_fast.h>
#include <sgl/test.h>


template<typename T, typename Allocator>
void test_empty_queue(const sgl::queue<T, Allocator>& queue) {
  assert(queue.size() == 0ul);
  assert(queue.capacity() >= queue.size());
  assert(queue.begin() == queue.end());
}

template<typename T, typename A>
void test_default_constructed_queue(const sgl::queue<T, A>& queue) {
  test_empty_queue(queue);
  assert(queue.capacity() == 0ul);
  assert(queue.size() == 0ul);
}

template<typename T, typename Allocator>
void test_one_element_queue(const sgl::queue<T, Allocator>& queue, const T& x) {
  assert(queue.size() == 1ul);
  assert(queue.capacity() >= queue.size());
  assert(*queue.begin() == x);
  assert(queue.front() == x);
  assert(queue.back() == x);
  assert(*(queue.end() - 1ul) == x);
}

void test_queue_0() {
  std::cout << "test_queue_0" << std::endl;
  sgl::queue<int> queue;
  test_default_constructed_queue(queue);

  auto queue_copy = queue;
  test_default_constructed_queue(queue_copy);

  assert(queue == queue_copy);

  int value = 13;
  queue.push_back(value);
  test_one_element_queue(queue, value);
  assert(queue != queue_copy);
  queue.pop_front();
  test_empty_queue(queue);
}


void test_queue_1() {
  std::cout << "test_queue_1" << std::endl;

  sgl::queue<int> queue(2, 0);

  assert(queue.front() == queue[0]);
  assert(queue[0] == 0);
  assert(queue[1] == 0);
  assert(queue.capacity() == 2ul);
  assert(queue.size() == 2ul);
  assert(static_cast<size_t>(std::end(queue) - std::begin(queue)) == queue.size());

  queue[0] = 1;
  queue[1] = 2;
  assert(queue.front() == queue[0]);
  assert(*queue.begin() = 1);
  assert(*(queue.begin() + 1) = 2);
  assert(static_cast<size_t>(std::end(queue) - std::begin(queue)) == queue.size());

  queue.pop_front();
  assert(queue[0] == 2);
  assert(queue.capacity() == 2ul);
  assert(queue.size() == 1ul);
  queue.push_back(3);
  assert(queue.capacity() == 4ul);

  queue.push_back(3);
}

void test_queue_4() {
  std::cout << "test_queue_4" << std::endl;
  sgl::queue<int> queue;
  queue.resize(10ul);
  assert(queue.size() == 10ul);
  assert(queue.capacity() == 10ul);
  queue.resize(10ul);
}

void test_queue_3() {
  std::cout << "test_queue_3" << std::endl;

  sgl::queue<int> values;

  values.reserve(10);
  assert(values.capacity() >= 10);
  values.push_back(1); 
  values.push_back(2); 
  values.push_back(3); 
  values.push_back(4); 

  int expected_values0[] = {1, 2, 3, 4};
  assert(sgl::equal_ranges(std::begin(values), std::end(values), std::begin(expected_values0), std::end(expected_values0)));

  int expected_values1[] = {2, 3, 4};
  values.pop_front(); 
  assert(sgl::equal_ranges(std::begin(values), std::end(values), std::begin(expected_values1), std::end(expected_values1)));
}

void test_queue_5() {
    std::cout << "test_queue_5\n";
    sgl::queue<int> values(1ul, 4);
    values.push_back(13);
    values.push_back(13);
    values.push_back(13);
    values.pop_front();
    values.pop_front();
    values.pop_front();
    values.insert(std::begin(values), 3);
    assert(values.size() == 1);
    assert(values.front() == 3);
}

void test_queue_6() {
    std::cout << "test_queue_6\n";
    sgl::queue<int> values(4ul, 14);
    values.reserve(5);
    values.insert(std::begin(values), 1);
    assert(values[0] == 1);
    assert(values[1] == 14);
    assert(values[2] == 14);
    assert(values[3] == 14);
    assert(values[4] == 14);
    assert(values.size() == 5ul);
    assert(values.capacity() == 5ul);
}

void test_queue_7() {
    std::cout << "test_queue_7\n";
    sgl::queue<int> values(0);
    values.reserve(1);
    values.insert(std::begin(values), 1);
    assert(values[0] == 1);
    assert(values.size() == 1ul);
    assert(values.capacity() == 1ul);
}




int main() {
  sgl::testing(__FILE__)([] {
    test_queue_0();
    test_queue_1();
    test_queue_3();
    test_queue_4();
    test_queue_5();
    test_queue_6();
    test_queue_7();
  });
}
