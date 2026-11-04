#include "part2_functions.hpp"

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace part2;

int main() {
    int passed = 0;
    int failed = 0;

    // Test 1: Power
    try {
        double result = power(2.0, 3.0);

        if (std::fabs(result - 8.0) < 0.000001) {
            std::cout << "PASS: Power test\n";
            passed++;
        } else {
            std::cout << "FAIL: Power test\n";
            failed++;
        }
    } catch (...) {
        std::cout << "FAIL: Power test\n";
        failed++;
    }

    // Test 2: Square root
    try {
        double result = squareRoot(25.0);

        if (std::fabs(result - 5.0) < 0.000001) {
            std::cout << "PASS: Square root test\n";
            passed++;
        } else {
            std::cout << "FAIL: Square root test\n";
            failed++;
        }
    } catch (...) {
        std::cout << "FAIL: Square root test\n";
        failed++;
    }

    // Test 3: Absolute value
    try {
        double result = absoluteValue(-10.0);

        if (std::fabs(result - 10.0) < 0.000001) {
            std::cout << "PASS: Absolute value test\n";
            passed++;
        } else {
            std::cout << "FAIL: Absolute value test\n";
            failed++;
        }
    } catch (...) {
        std::cout << "FAIL: Absolute value test\n";
        failed++;
    }

    // Test 4: Exponential
    try {
        double result = exponential(0.0);

        if (std::fabs(result - 1.0) < 0.000001) {
            std::cout << "PASS: Exponential test\n";
            passed++;
        } else {
            std::cout << "FAIL: Exponential test\n";
            failed++;
        }
    } catch (...) {
        std::cout << "FAIL: Exponential test\n";
        failed++;
    }

    // Test 5: Negative square root
    try {
        squareRoot(-4.0);
        std::cout << "FAIL: Negative square root test\n";
        failed++;
    } catch (const std::domain_error&) {
        std::cout << "PASS: Negative square root test\n";
        passed++;
    }

    // Test 6: Power overflow
    try {
        power(10.0, 1000.0);
        std::cout << "FAIL: Power overflow test\n";
        failed++;
    } catch (const std::overflow_error&) {
        std::cout << "PASS: Power overflow test\n";
        passed++;
    }

    // Test 7: Exponential overflow
    try {
        exponential(1000.0);
        std::cout << "FAIL: Exponential overflow test\n";
        failed++;
    } catch (const std::overflow_error&) {
        std::cout << "PASS: Exponential overflow test\n";
        passed++;
    }

    std::cout << "\nTest Summary\n";
    std::cout << "Passed: " << passed << '\n';
    std::cout << "Failed: " << failed << '\n';

    return (failed == 0) ? 0 : 1;
}
