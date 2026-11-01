1. Overview
   Part 3 is responsible for consistent handling of floating-point values and invalid numerical inputs across the Mathematical
   Functions module. Parts 1 and 2 perform array arithmetic and scalar mathematical operations while Part 3 provides common
   numerical-safety helpers that those functions can use so that input checks and result checks follow the same rules.
   This part does not introduce another set of mathematical operations. It supports the existing operations by checking whether
   values are valid for computation and whether calculated results remain valid.

2. Scope and responsibilities
    Part 3 covers the following:
    Checking whether a floating-point value is finite.
    Checking collections of floating-point values for invalid entries.
    Checking calculated results so that NaN or infinity is not returned as an ordinary result.
    Providing a consistent way to compare floating-point results approximately when testing.
    Using clear and consistent error handling for invalid inputs and invalid results.
    A finite number is a value that is neither NaN (Not a Number) nor positive or negative infinity.

 3. Proposed module files
    The proposed files are: part3_numeric.hpp — declares the common numerical-safety helper functions.
    part3_numeric.cpp — implements the helper functions.
    test_part3.cpp — tests the helper functions using practical numerical examples and invalid-value cases.
    The exact filenames and function signatures shall be confirmed with the group before integration so that they agree with the
    project's shared conventions.

4. Proposed helper functionality
    Helper responsibility                Purpose
    Check a scalar value                 Determine whether one double value is finite
    Check an array of values             Determine whether every element in an array is finite.
    Check a computed result              Prevent a non-finite result from being treated as a valid answer
    Compare floating-point values        Check whether two results are sufficiently close, using a specified tolerance.

5. Floating-point comparison
   Floating-point calculations can produce small rounding differences.
   Therefore, tests shall not always compare decimal results using exact equality.
   A common comparison rule is:
   abs(actual- expected) <= tolerance For example, if the expected result is 0.3 and the calculated result is 0.3000000001,
   a small suitable tolerance can allow the test to recognise the values as approximately equal. The tolerance shall be
   chosen and documented consistently by the project team and not be selected arbitrarily for each individual test.

6. Invalid values and error handling
   The module shall recognise non-finite values, including:
   NaN (Not a Number).
   Positive infinity.
   Negative infinity. Invalid inputs or results shall be handled consistently with the project's agreed error-handling convention.
   For example, the team will choose standard C++ exceptions such as std::invalid_argument for invalid input and
   std::overflow_error for a non-finite result caused by a calculation.

 7. Practical examples
    Examples that can be used when 9. Integration with Parts 1 and 2 Part 3 is intended to provide shared helpers for the mathematical functions developed in the earlier parts. Before integration, the group should agree on: The project's common array type. The names and signatures of the helper functions. The floating-point tolerance to use in tests. The exception types and error messages to use. Once these conventions are agreed, Parts 1 and 2 can use the shared helpers instead of maintaining different versions of the same checks.testing include:
    Checking that 12.5 is a finite value.
    Checking that an array such as {2.5, 4.0, 6.75} contains only finite values.
    Detecting NaN in an array. Detecting positive or negative infinity.
    Comparing 0.3 with 0.1 + 0.2 using a suitable tolerance.
    Checking that a computed result that becomes infinity is reported as invalid.

 8. Testing plan
     test_part3.cpp shall include:
     1. Valid finite scalar values.
     2. Arrays containing only finite values.
     3. NaN and positive/negative infinity.
     4. Floating-point comparisons where a small rounding difference occurs.
     5. Invalid values and results that should trigger the agreed error-handling behaviour.
     Tests shasll use clear inputs, expected outcomes and readable pass/fail messages.
     The README describes the planned tests; test results will only be reported after the program has actually been compiled and
     run.

9. Integration with Parts 1 and 2
     Part 3 is intended to provide shared helpers for the mathematical functions developed in the earlier parts.
     Before integration, the group will agree on:
     The project's common array type.
     The names and signatures of the helper functions.
     The floating-point tolerance to use in tests.
     The exception types and error messages to use.
     Once these conventions are agreed, Parts 1 and 2 can use the shared helpers instead of maintaining different versions of the
     same checks.

11. Conclusion
     Part 3 supports the reliability of the Mathematical Functions module by establishing consistent checks for floating-point
     inputs and results. It also provides a suitable comparison approach for decimal-number tests. Its purpose is to support
     Parts 1 and 2, avoid duplicated checking logic and make the complete library more consistent.
   
  
    
