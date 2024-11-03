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
add_executable(runtest test/unit_tests.cpp
    test/insertion-test.cpp test/initialization-test.cpp
    test/size-test.cpp)
target_link_libraries(runtest gtest gtest_main)