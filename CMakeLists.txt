
cmake_minimum_required(VERSION 3.16)

project(numerical_computation1 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==============================
# Library source files
# ==============================

add_library(numerical_computation1
    src/ndarray.cpp
    src/statistics.cpp
    src/indexing.cpp
    src/array_creation.cpp
    src/array_utils.cpp
    src/aggregation.cpp
    src/matrix.cpp
    src/broadcasting.cpp
    src/elementwise.cpp
    src/linalg.cpp
    src/random.cpp
    src/part1_arithmetic.cpp
    src/part2_Mathematical_functions.cpp
    src/part3_Floating_Point_and_Invalid_Input.cpp
)

target_include_directories(numerical_computation1
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(numerical_computation1
    PRIVATE -Wall -Wextra -Wpedantic
)

# ==============================
# Examples
# ==============================

function(add_example target source)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE numerical_computation1)
endfunction()

add_example(statistics_example examples/statistics_example.cpp)
add_example(ndarray_example examples/ndarray_example.cpp)
add_example(indexing_example examples/indexing_example.cpp)
add_example(creation_example examples/creation_example.cpp)
add_example(types_example examples/types_example.cpp)
add_example(matrix_example examples/matrix_example.cpp)

# Aggregation example moved from src to examples
add_example(aggregation_example examples/aggregation_example.cpp)

add_example(benchmark_broadcast examples/benchmark_broadcast.cpp)

# Part 1, 2 and 3 examples
add_example(part1_examples examples/part1_examples.cpp)
add_example(part2_examples examples/part2_examples.cpp)
add_example(part3_examples examples/part3_examples.cpp)


# ==============================
# Testing
# ==============================

enable_testing()

function(add_project_test target source)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE numerical_computation1)
    add_test(NAME ${target} COMMAND ${target})
endfunction()

# Existing tests
add_project_test(test_ndarray tests/test_ndarray.cpp)
add_project_test(test_indexing tests/test_indexing.cpp)
add_project_test(test_creation tests/test_creation.cpp)
add_project_test(test_array_utils tests/test_array_utils.cpp)
add_project_test(test_matrix tests/test_matrix.cpp)
add_project_test(test_statistics tests/test_statistics.cpp)
add_project_test(test_aggregation tests/test_aggregation.cpp)
add_project_test(test_random tests/test_random.cpp)
add_project_test(test_broadcasting tests/test_broadcasting.cpp)

# Part 1, 2 and 3 tests
add_project_test(part1_test tests/part1_test.cpp)
add_project_test(part2_tests tests/part2_tests.cpp)
add_project_test(part3_test tests/part3_test.cpp)

# Newly added tests
add_project_test(test_addition tests/test_addition.cpp)
add_project_test(test_linalg tests/test_linalg.cpp)
add_project_test(test_elementwise tests/test_elementwise.cpp)


# ==============================
# Application
# ==============================

add_executable(numerical_cli app/main.cpp)
target_link_libraries(numerical_cli PRIVATE numerical_computation1)


# ==============================
# Copy sample datasets
# ==============================

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
