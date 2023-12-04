cmake_minimum_required(VERSION 3.10)
project(lab1)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab12 main.cpp box_capacity.cpp)

enable_testing()
add_executable(tests tests.cpp box_capacity.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)
