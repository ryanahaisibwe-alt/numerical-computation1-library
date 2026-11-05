# Week 2 Progress Report — Linear Algebra Module
Name: Mwidhu Hamza
Group: 22 (Numerical Computing Project)
Assigned Focus: Vector arithmetic, dot products, norms, and matrix-vector compatibility

# What We Did This Week
Moved from planning into active implementation for our individual modules.
Focused on building out the vector math components, ensuring they tie cleanly into the shared NDArray interface.

# Design & Technical Approach
Vector Operations: Implemented core logic for vector arithmetic, dot products (sum of pairwise products), and Euclidean norms (square root of sum of squares).
Validation & Safety: Added checks for matrix-vector multiplication to ensure input vector lengths match column counts, and implemented checks to reject incompatible dimensions or invalid inputs before any data access occurs.

# Code Structure: Maintained a clean split between header (.hpp) declarations and source (.cpp) definitions, adhering to our agreed-upon namespaces and exception policies.

# Testing Plan
Planned small, hand-checkable unit tests using known-answer arrays.
Focused testing scope on both normal valid cases and edge cases (such as dimension mismatches or invalid shapes) to verify correct numerical output, element order, and error behavior.

# Challenges & Risks
Consistency: Maintaining strict alignment across shared conventions like array interfaces, namespaces, error handling, and axis numbering across different team modules. Any discrepancies need immediate team coordination before full integration.

# Plan for Week 3
Finish up the main numerical logic for the vector module.
Expand the test suite with edge cases and integration checks.
Verify clean compilation and successful integration with the shared array representation.