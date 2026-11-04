#include "part3_Floating_Point_and_Invalid_Input.hpp"

#include <iostream>
#include <cassert>
#include <limits>

int main() {

    // Test 1: Check whether a single value is finite
    assert(part3::isFinite(25.5) == true);
    assert(part3::isFinite(-10.0) == true);
    assert(part3::isFinite(std::numeric_limits<double>::infinity()) == false);
    assert(part3::isFinite(std::numeric_limits<double>::quiet_NaN()) == false);

    // Test 2: Check whether all array values are finite
    part3::Array values1 = {2.5, 4.0, 6.5};
    part3::Array values2 = {2.5, std::numeric_limits<double>::infinity(), 6.5};

    assert(part3::areFinite(values1) == true);
    assert(part3::areFinite(values2) == false);

    // Test 3: Compare approximately equal values
    assert(part3::approximatelyEqual(5.000001, 5.0, 0.00001) == true);
    assert(part3::approximatelyEqual(5.5, 5.0, 0.1) == false);

    // Test 4: Check invalid tolerance
    assert(part3::approximatelyEqual(5.0, 5.0, -0.1) == false);

    // Test 5: Check non-finite inputs
    assert(part3::approximatelyEqual(
        std::numeric_limits<double>::infinity(), 5.0, 0.01
    ) == false);

    std::cout << "All Part 3 tests passed successfully!" << std::endl;

    return 0;
}
