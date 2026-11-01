1. Overview
   Part 3 shall support the Mathematical Functions module by providing a consistent approach to handling floating-point values and
   invalid numerical inputs. It shall complement the array arithmetic in Part 1 and the scalar mathematical operations in Part 2.

 2. Main responsibilities
   The module shall check whether individual values and arrays contain finite numbers.
   It shall detect invalid values such as NaN (Not a Number), positive infinity and negative infinity.
   It shall also check calculated results before they are treated as valid answers and provide a consistent approach to comparing
   floating-point results.

3. Floating-point comparison
   Floating-point calculations may produce small rounding differences. Therefore, decimal results shall be compared using an
   agreed tolerance rather than relying exclusively on exact equality. The comparison shall follow the rule
   |actual - expected| <= tolerance. The project team shall agree on the tolerance so that it is applied consistently throughout
   the tests.

 4. Invalid inputs and error handling
    The module shall identify NaN and infinite values and shall handle invalid inputs or results according to the error-handling
    convention agreed upon by the group. Standard C++ exceptions, such as std::invalid_argument for invalid input and
    std::overflow_error for an invalid calculation result, may be used. Invalid values shall not be silently replaced with ordinary
    values such as zero.

 5. Testing and integration
    The test program shall cover ordinary finite values, arrays containing finite values, NaN, positive and negative infinity,
    and decimal comparisons affected by rounding. The helper functions shall be designed for use by Parts 1 and 2 so that numerical
    checks are not duplicated. Before integration, the group shall agree on the common array type, helper names and signatures,
    comparison tolerance, and exception conventions.

 6. Conclusion
    Part 3 shall improve the consistency and reliability of the Mathematical Functions module by providing shared checks for
    floating-point inputs and results. It shall also support accurate testing of decimal calculations and help Parts 1 and 2
    follow the same numerical-safety rules. 
