1. Summary
   The module provides four scalar mathematical operations: power, square root, absolute value, and exponential.
   It separates the public declarations from the implementation so that the functions can be reused and tested.

 2. Module Structure
    The module consists of three planned files.
    The header file, part2_functions.hpp, declares the functions. The source file, part2_functions.cpp, implements them.
    The test file, test_part2.cpp, is intended to check normal operation and selected error cases. All files should be kept
    in the same folder unless the compilation command is adjusted.

3. Mathematical Functions
   The power function uses std::pow(base, exponent) to raise a base to an exponent; for example, power(2, 3) returns 8.
   The squareRoot function uses std::sqrt(x) and returns 5 for an input of 25. It rejects negative inputs with std::domain_error.
   The absoluteValue function uses std::fabs(x) to return a number's non-negative magnitude, so absoluteValue(-7) returns 7.
   The exponential function uses std::exp(x) to calculate e^x; exponential(1) is approximately 2.71828.

 4. Error Handling
   The implementation throws std::domain_error when the square-root function receives a negative input.
   It also checks the results of power and exponential operations and throws std::overflow_error if a result is not finite.
   A program that calls these functions can catch the exceptions and handle the errors.

5. Example and Expected Output
   A program includes part2_functions.hpp and calls the functions through the part2 namespace.
   For inputs power(2, 3), squareRoot(25), absoluteValue(-7), and exponential(1), the expected outputs are 8, 5, 7, and
   approximately 2.71828, respectively.

6. Conclusion
   As summarized in the README, Part 2 provides a reusable implementation of four mathematical functions.
   Its separate header and source files make the module easier to maintain, while exception checks identify selected invalid
   operations. 
