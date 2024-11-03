cmake_minimum_required(VERSION 3.10) 

project(separate_chaining_hashmap)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(main src/main.cpp)

# TESTING FRAMEWORK
add_subdirectory(third_party/googletest)
include_directories(third_party/googletest/googletest/include)

enable_testing()
add_executable(unit_test tests/unit_tests.cpp)
target_link_libraries(unit_test gtest gtest_main)