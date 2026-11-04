#include "part2_functions.hpp"

#include <iostream>

using namespace part2;

int main() {

    // Example 1: Calculate the area of a square
    double side = 5.0;
    double area = power(side, 2.0);

    std::cout << "Area of square: " << area << '\n';

    // Example 2: Calculate the square root of a number
    double number = 144.0;
    double root = squareRoot(number);

    std::cout << "Square root of 144: " << root << '\n';

    // Example 3: Calculate the magnitude of a negative value
    double temperatureChange = -15.0;
    double magnitude = absoluteValue(temperatureChange);

    std::cout << "Magnitude of temperature change: "
              << magnitude << '\n';

    // Example 4: Calculate exponential growth
    double x = 2.0;
    double growth = exponential(x);

    std::cout << "Exponential value of 2: "
              << growth << '\n';

    return 0;
}
