
cmake_minimum_required(VERSION 3.10)

project(numerical-computation1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(numerical-computation1
    src/statistics.cpp
    src/ndarray.cpp
)

target_include_directories(numerical-computation1
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(statistics_example
    examples/statistics_example.cpp
)

target_link_libraries(statistics_example
    numerical-computation1
)

add_executable(ndarray_example
    examples/ndarray_example.cpp
)

target_link_libraries(ndarray_example
    numerical-computation1
)

enable_testing()

add_executable(test_ndarray
    tests/test_ndarray.cpp
)

target_link_libraries(test_ndarray
    numerical-computation1
)

add_test(
    NAME ndarray_test
    COMMAND test_ndarray
)

cmake_minimum_required(VERSION 3.20)
project(ShadicLibrary VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(shadic_core src/broadcasting.cpp)
target_include_directories(shadic_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(benchmark_broadcast examples/benchmark_broadcast.cpp)
target_link_libraries(benchmark_broadcast PRIVATE shadic_core)
