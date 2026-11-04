#include <iostream>
#include <vector>
#include <cassert>
#include "broadcasting.hpp"

// Simple test runner helper
void run_test(const std::string& test_name, void(*test_func)()) {
    try {
        test_func();
        std::cout << "[PASS] " << test_name << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[FAIL] " << test_name << " - Error: " << e.what() << "\n";
    }
}

// Test 1: Standard NumPy-style broadcasting (equal dimensions or 1s)
void test_standard_broadcasting() {
    using Shape = shadic::ShapeTracker::Shape;
    Shape s1 = {2, 1, 4};
    Shape s2 = {    3, 4};
    
    Shape expected = {2, 3, 4};
    Shape result = shadic::ShapeTracker::broadcast_shapes(s1, s2);
    
    assert(result == expected);
}

// Test 2: Broadcasting with scalar/empty shapes
void test_scalar_broadcasting() {
    using Shape = shadic::ShapeTracker::Shape;
    Shape s1 = {5, 3, 2};
    Shape s2 = {}; // Scalar equivalent
    
    Shape result = shadic::ShapeTracker::broadcast_shapes(s1, s2);
    assert(result == s1);
}

// Test 3: Incompatible shapes that should fail or throw an exception
void test_incompatible_shapes() {
    using Shape = shadic::ShapeTracker::Shape;
    Shape s1 = {2, 3};
    Shape s2 = {5, 2}; // Dimensions 3 and 5 are incompatible
    
    bool exception_thrown = false;
    try {
        volatile auto res = shadic::ShapeTracker::broadcast_shapes(s1, s2);
        (void)res;
    } catch (...) {
        exception_thrown = true;
    }
    

    assert(exception_thrown || shadic::ShapeTracker::broadcast_shapes(s1, s2).empty());
}

int main() {
    std::cout << "Running ShapeTracker Unit Tests...\n";
    
    run_test("Standard NumPy Broadcasting", test_standard_broadcasting);
    run_test("Scalar/Empty Broadcasting", test_scalar_broadcasting);
    run_test("Incompatible Shapes Handling", test_incompatible_shapes);
    
    std::cout << "All tests executed successfully!\n";
    return 0;
}