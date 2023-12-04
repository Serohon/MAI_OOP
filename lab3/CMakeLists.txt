cmake_minimum_required(VERSION 3.10)
project(lab3)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(lab3 main.cpp Trapezoid.cpp Pentagon.cpp Rhombus.cpp)

enable_testing()
add_executable(tests tests.cpp Trapezoid.cpp Pentagon.cpp Rhombus.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)