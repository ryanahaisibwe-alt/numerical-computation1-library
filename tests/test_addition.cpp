#include <iostream>
#include <vector>
#include <cassert>
#include "addition.hpp"

void run_test(const std::string& test_name, void(*test_func)()) {
    try {
        test_func();
        std::cout << "[PASS] " << test_name << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[FAIL] " << test_name << " - Error: " << e.what() << "\n";
    }
}

void test_elementwise_addition() {
    std::vector<float> a = {1.0f, 2.0f, 3.0f};
    std::vector<float> b = {10.0f, 20.0f, 30.0f};
    
    std::vector<float> result = hamza::Addition::add(a, b);
    
    assert(result.size() == 3);
    assert(result[0] == 11.0f);
    assert(result[1] == 22.0f);
    assert(result[2] == 33.0f);
}

int main() {
    std::cout << "Running Addition Unit Tests...\n";
    run_test("Element-wise Addition", test_elementwise_addition);
    std::cout << "All addition tests passed successfully!\n";
    return 0;
}