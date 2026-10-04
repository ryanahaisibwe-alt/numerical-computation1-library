cmake_minimum_required(VERSION 3.10)

project(numerical-computation1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(numerical-computation1
    src/statistics.cpp
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
