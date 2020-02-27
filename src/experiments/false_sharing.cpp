#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <atomic>


void use_atomic(std::atomic<int>& x) {
    for (size_t i = 0; i < 10000; ++i) {
        ++x;
    }
}

int slow1() {
    std::atomic<int> x0[1];

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t0([&](){use_atomic(x0[0]);});

    t0.join();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int slow2() {
    std::atomic<int> x0[1];
    std::atomic<int> x1[1];

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t0([&](){use_atomic(x0[0]);});
    std::thread t1([&](){use_atomic(x1[0]);});

    t0.join();
    t1.join();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int slow3() {
    std::atomic<int> x0[1];
    std::atomic<int> x1[1];
    std::atomic<int> x2[1];

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t0([&](){use_atomic(x0[0]);});
    std::thread t1([&](){use_atomic(x1[0]);});
    std::thread t2([&](){use_atomic(x2[0]);});

    t0.join();
    t1.join();
    t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}


int slow4() {
    std::atomic<int> x0[1];
    std::atomic<int> x1[1];
    std::atomic<int> x2[1];
    std::atomic<int> x3[1];

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t0([&](){use_atomic(x0[0]);});
    std::thread t1([&](){use_atomic(x1[0]);});
    std::thread t2([&](){use_atomic(x2[0]);});
    std::thread t3([&](){use_atomic(x3[0]);});

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int fast4() {
    std::atomic<int> x0[100];
    std::atomic<int> x1[100];
    std::atomic<int> x2[100];
    std::atomic<int> x3[100];

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t0([&](){use_atomic(x0[0]);});
    std::thread t1([&](){use_atomic(x1[0]);});
    std::thread t2([&](){use_atomic(x2[0]);});
    std::thread t3([&](){use_atomic(x3[0]);});

    t0.join();
    t1.join();
    t2.join();
    t3.join();

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

template<typename F>
double repeat(F f, size_t n) {
    std::vector<int> m(n);
    for (auto& x : m) x = f();
    std::nth_element(m.begin(), m.begin() + n / 2, m.end());
    return m[n / 2];
}


int main() {
    size_t n = 10000;
    std::cout << "slow1: " << repeat(slow1, n) / 1.0 << std::endl;
    std::cout << "slow2: " << repeat(slow2, n)/ 2.0 << std::endl;
    std::cout << "slow3: " << repeat(slow3, n) / 3.0 << std::endl;
    std::cout << "slow4: " << repeat(slow4, n) / 4.0 << std::endl;
    std::cout << "fast4: " << repeat(fast4, n) / 4.0 << std::endl;
}
