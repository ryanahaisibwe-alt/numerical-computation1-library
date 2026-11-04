#include "part1_arithmetic.hpp"

#include <iostream>

using namespace part1;

int main() {

    // Example: Two sets of student marks
    Array mathematics = {70, 80, 65};
    Array electronics = {60, 75, 85};

    // Addition of marks
    Array total = add(mathematics, electronics);

    // Difference between marks
    Array difference = subtract(mathematics, electronics);

    // Multiplication of values
    Array product = multiply(mathematics, electronics);

    // Division of values
    Array ratio = divide(mathematics, electronics);

    std::cout << "Total marks:\n";

    for (double value : total)
        std::cout << value << " ";

    std::cout << "\nDifference:\n";

    for (double value : difference)
        std::cout << value << " ";

    std::cout << "\nProduct:\n";

    for (double value : product)
        std::cout << value << " ";

    std::cout << "\nRatio:\n";

    for (double value : ratio)
        std::cout << value << " ";

    std::cout << std::endl;

    return 0;
}
