cmake_minimum_required(VERSION 3.10)
project(lab2)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(lab2 main.cpp Money.cpp)

enable_testing()
add_executable(tests tests.cpp Money.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)
