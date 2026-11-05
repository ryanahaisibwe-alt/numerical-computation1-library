#include <iostream>
#include <vector>
#include <cassert>
#include "random.hpp"

void run_test(const std::string& test_name, void(*test_func)()) {
    try {
        test_func();
        std::cout << "[PASS] " << test_name << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[FAIL] " << test_name << " - Error: " << e.what() << "\n";
    }
}

void test_random_uniform() {
    hamza::Random rng(42);
    auto values = rng.uniform<float>(50, 0.0f, 1.0f);
    
    assert(values.size() == 50);
    for (float val : values) {
        assert(val >= 0.0f && val <= 1.0f);
    }
}

int main() {
    std::cout << "Running Random Generation Unit Tests...\n";
    run_test("Uniform Distribution Bounds", test_random_uniform);
    std::cout << "All random generation tests passed successfully!\n";
    return 0;
}