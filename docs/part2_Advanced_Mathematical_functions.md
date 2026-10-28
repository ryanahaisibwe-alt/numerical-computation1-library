1. Overview
   Part 2 implements four scalar mathematical functions in C++:
   Power — raises a base to an exponent.
   Square root — calculates the square root of a value.
   Absolute value — returns the non-negative magnitude of a value.
   Exponential — calculates e^x, where e is approximately 2.71828.
   The functions are placed in the part2 namespace to keep them organized and reduce the chance of naming conflicts.

2. Public interface
   The header declares these functions:
   double power(double base, double exponent);
   double squareRoot(double x);
   double absoluteValue(double x);
   double exponential(double x);
   Each function receives one or two double values and returns a double.

   3. Function behaviour
    Power
    power(base, exponent) calculates the base raised to the given exponent using std::pow().
    Example: power(2, 3) returns 8.
    The implementation checks whether the result is finite. If the result is not finite, it throws std::overflow_error.

    Square root
    squareRoot(x) calculates the square root using std::sqrt().
    Example: squareRoot(25) returns 5.
    For real-valued calculations, the implementation rejects negative inputs by throwing std::domain_error.

    Absolute value
    absoluteValue(x) uses std::fabs() to return the absolute value.
    Example: absoluteValue(-7) returns 7.

    Exponential
    exponential(x) calculates e^x using std::exp().
    Example: exponential(1) returns approximately 2.71828.
    The implementation checks whether the result is finite. If it is not finite, it throws std::overflow_error. 
    
  4. Error handling
     The implementation uses exceptions to report certain invalid operations:
     std::domain_error is thrown when the square-root function receives a negative value.
     std::overflow_error is thrown when the power or exponential function produces a non-finite result.
     A calling program can catch these exceptions to handle errors without abruptly terminating.

  5. Testing plan test_part2.cpp will test:
     Normal values for all four functions.
     A negative input for absolute value.
     A negative input to square root, which should throw std::domain_error.
     A power calculation that produces a non-finite result, which should throw std::overflow_error.
     An exponential calculation that produces a non-finite result, which should throw std::overflow_error.
     The README will be updated if the implementation or test cases change.

  6. Design summary
     The module separates the public interface from the implementation.
     The header declares the functions, while the .cpp file contains the calculations.
     This structure makes the module easier to reuse, test, and maintain.
