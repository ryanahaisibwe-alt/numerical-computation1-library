#include "part1_arithmetic.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace part1;

int main() {

    // Test 1: Element-wise addition
    Array a = {10, 20, 30};
    Array b = {2, 4, 5};

    Array sum = add(a, b);

    assert(sum[0] == 12);
    assert(sum[1] == 24);
    assert(sum[2] == 35);

    std::cout << "Addition test passed.\n";


    // Test 2: Element-wise subtraction
    Array difference = subtract(a, b);

    assert(difference[0] == 8);
    assert(difference[1] == 16);
    assert(difference[2] == 25);

    std::cout << "Subtraction test passed.\n";


    // Test 3: Element-wise multiplication
    Array product = multiply(a, b);

    assert(product[0] == 20);
    assert(product[1] == 80);
    assert(product[2] == 150);

    std::cout << "Multiplication test passed.\n";


    // Test 4: Element-wise division
    Array quotient = divide(a, b);

    assert(quotient[0] == 5);
    assert(quotient[1] == 5);
    assert(quotient[2] == 6);

    std::cout << "Division test passed.\n";


    // Test 5: Arrays with unequal sizes
    try {
        Array c = {1, 2};
        Array d = {3, 4, 5};

        add(c, d);

        assert(false);
    }
    catch (const std::invalid_argument&) {
        std::cout << "Unequal array size test passed.\n";
    }


    // Test 6: Division by zero
    try {
        Array e = {10, 20};
        Array f = {2, 0};

        divide(e, f);

        assert(false);
    }
    catch (const std::domain_error&) {
        std::cout << "Division by zero test passed.\n";
    }


    std::cout << "\nAll tests completed successfully!\n";

    return 0;
}
