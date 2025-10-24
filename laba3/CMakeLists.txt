cmake_minimum_required(VERSION 3.10)
project(Lab03)

set(CMAKE_CXX_STANDARD 17)

# Main executable
add_executable(laba3
    src/main.cpp
    src/Figure.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/Triangle.cpp
)

target_include_directories(laba3 PRIVATE include)

# Tests
enable_testing()

find_package(GTest REQUIRED)

add_executable(test_figures test/test_figures.cpp
    src/Figure.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/Triangle.cpp
)

target_include_directories(test_figures PRIVATE include)
target_link_libraries(test_figures GTest::gtest GTest::gtest_main)

add_test(NAME FigureTests COMMAND test_figures)