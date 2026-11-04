#include <iostream>
#include "addition.hpp"

int main() {
    std::cout << "=== Testing numlib ===" << std::endl;

    // 1. Test Random Number Generation
    auto vec_a = numlib::random_uniform(3, 1.0, 10.0);
    auto vec_b = numlib::random_uniform(3, 1.0, 10.0);

    std::cout << "Vector A: [" << vec_a[0] << ", " << vec_a[1] << ", " << vec_a[2] << "]" << std::endl;
    std::cout << "Vector B: [" << vec_b[0] << ", " << vec_b[1] << ", " << vec_b[2] << "]" << std::endl;

    // 2. Test Element-wise Addition
    auto sum_vec = numlib::add(vec_a, vec_b);
    std::cout << "Sum (A + B): [" << sum_vec[0] << ", " << sum_vec[1] << ", " << sum_vec[2] << "]" << std::endl;

    // 3. Test Linear Algebra Dot Product
    double dot_val = numlib::dot(vec_a, vec_b);
    std::cout << "Dot Product (A . B): " << dot_val << std::endl;

    return 0;
}
