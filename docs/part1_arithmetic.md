1.Module purpose;
This module provides element-wise addition, subtraction, multiplication and division for numeric arrays. Each output element is calculated from the input elements at the same index.

2. Public interface;
The interface is declared in part1_arithmetic.hpp and implemented in part1_arithmetic.cpp.
namespace math_part1
{ using Array = std::vector<double>; 
Array add(const Array& a, const Array& b); 
Array subtract(const Array& a, const Array& b);
Array multiply(const Array& a, const Array& b);
Array divide(const Array& a, const Array& b); }
This implementation currently uses std::vector<double> as a standalone placeholder for my team's Array type.
I will adapt it if the team defines a shared Array class. Inputs are passed by constant reference and are not modified and each function returns a new result array.

3.Module design note
Element-wise rule;
For arrays a and b of equal length:
Addition: result[i] = a[i] + b[i] 
Subtraction: result[i] = a[i]- b[i] 
Multiplication: result[i] = a[i] * b[i] 
Division: result[i] = a[i] / b[i] 
Binary operations require equal array lengths hence is what was used. The module does not implement matrix multiplication, dot products or broadcasting.

Validation and error policy
Unequal array lengths throw std::invalid_argument.
NaN or infinity inputs throw std::invalid_argument. 
Division by 0.0 or-0.0 throws std::domain_error.
Non-finite arithmetic results throw std::overflow_error.
Two empty arrays are valid and produce an empty result. 
An invalid element causes the whole operation to fail; no partial result is returned. 
The calling code should catch the exception and display an appropriate message.

Implementation structure
A shared internal helper also known as a function inside C++ implementation that is used by several other functions to avoid repeating the same code checks equal lengths, validates input values, applies the operation and checks the result. The four public functions pass their arithmetic expression to this helper, reducing duplicated logic.

4.Tests
test_part1.cpp tests addition, subtraction, multiplication, division, empty arrays, division by zero, unequal lengths and overflow. Floating-point results are compared with a tolerance. The recorded output is in test_results.txt.

5.Integration notes
Before integration of the notes, we shall agree on the shared Array interface, numeric type, shape conventions, broadcasting policy and error rules. This version deliberately uses equal-length arrays and no broadcasting. Shared project validation utilities can replace local checks if they preserve the documented behaviour.

6.Module files
part1_arithmetic.hpp — public declarations.
part1_arithmetic.cpp — implementation. 
test_part1.cpp — test program.
test_results.txt — recorded test output. 
Part1_arithmetic.md —design note and usage instructions.
Part1_Arithmetic_Report.docx — summary of this README.
