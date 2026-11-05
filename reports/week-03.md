# Week 3 Progress Report — Linear Algebra Module
Name: Mwidhu Hamza
Group: 22 (Numerical Computing Project)
Assigned Focus: Advanced numerical logic, edge cases, floating-point precision, and module-level testing

# What We Did This Week
Shifted focus to the core numerical logic, edge cases, and robust testing for the assigned linear algebra functions.
Ensured our functions output the exact expected array shapes alongside accurate mathematical results.

# Numerical Logic & Validation
Core Functions: Refined vector arithmetic, dot products (pairwise sums), Euclidean norms (square root of sum of squares), and matrix-vector compatibility checks.
Input Validation: Verified that shape and dimension checks catch invalid inputs before execution to prevent runtime crashes or miscalculations during multiplication.

# Testing & Verification
Hand-Checked & Error Tests: Built tests covering standard valid operations, dimension mismatch errors, and boundary cases.
Floating-Point Precision: Used epsilon tolerances (|a - b| ≤ ε) for float comparisons instead of exact equality (==), avoiding test failures caused by standard rounding errors.

# Challenges & Lessons Learned
Beyond Correct Math: Realized that returning correct numbers isn't enough; shape, memory layout, axis rules, and error handling are just as critical.
Interface Alignment: Double-checked header files against the shared team interface to guarantee clean integration without build errors or redundant code.