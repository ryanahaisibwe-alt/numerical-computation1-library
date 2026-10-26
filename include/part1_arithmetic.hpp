#ifndef PART1_ARITHMETIC_HPP
#define PART1_ARITHMETIC_HPP

#include <vector>

namespace part1 {

using Array = std::vector<double>;

// Element-wise addition
Array add(const Array& a, const Array& b);

// Element-wise subtraction
Array subtract(const Array& a, const Array& b);

// Element-wise multiplication
Array multiply(const Array& a, const Array& b);

// Element-wise division
Array divide(const Array& a, const Array& b);

} // namespace part1

#endif // PART1_ARITHMETIC_HPP
