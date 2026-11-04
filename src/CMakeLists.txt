CMake
cmake_minimum_required(VERSION 3.20)
project(numlib_library CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(addition STATIC
    src/elementwise.cpp
    src/linalg.cpp
    src/random.cpp
)

target_include_directories(addition PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(tester main.cpp)
target_link_libraries(tester PRIVATE addition)
target_include_directories(tester PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)