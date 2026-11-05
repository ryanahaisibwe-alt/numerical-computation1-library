# Week 1 Progress Report — Linear Algebra Module
Name: Mwidhu Hamza
Group: 22 (Numerical Computing Project)
Assigned Focus: Vector arithmetic, dot products, and vector-matrix compatibility

# What We Did This Week
Reviewed the project repository structure and broke down the core requirements with the team.
Agreed on shared conventions for our NDArray interface—including row-major order, indexing rules, shape checks, and how we handle errors and exceptions.
Split up the workload: I'm taking care of the vector operations side, while coordinating closely with team members handling matrices.

# Design & Technical Decisions
Interface Alignment: Decided that vector operations must rely strictly on the core NDArray class dimensions to prevent mismatch bugs during arithmetic.
Structure: Planned out our header (.hpp) and implementation (.cpp) files, keeping everything modular so we can write focused unit tests and hook it up to CMake smoothly.
 # Challenges & Risks
Interface Consistency: The biggest risk early on is mismatched assumptions between different modules (e.g., how shapes are verified or how floating-point numbers are compared). We need strict error checks for invalid dimensions.

# Build Setup: We are still ironing out local CMake configurations and making sure our test suites build cleanly.
# Plan for Week 2
Start writing the actual C++ implementation for the vector module.
Set up basic, known-answer unit tests to verify vector math functions.
Test the local CMake build and resolve any integration or dependency issues early.