#include<gtest/gtest.h>
#include "separate_chaining_hashmap.h"
#include <string>

void init_string_int() {
    SeparateChainingHashMap<std::string, int> hmap;
}

void init_int_int() {
    SeparateChainingHashMap<int, int> hmap;
}

void init_double_int() {
    SeparateChainingHashMap<double, int> hmap;
}

void init_int_string() {
    SeparateChainingHashMap<int, std::string> hmap;
}

void init_string_string() {
    SeparateChainingHashMap<std::string, std::string> hmap;
}

TEST(SeparateChainingHashmap, Initialization) {
    EXPECT_NO_THROW(init_string_int());
    EXPECT_NO_THROW(init_int_int());
    EXPECT_NO_THROW(init_double_int());
    EXPECT_NO_THROW(init_int_string());
    EXPECT_NO_THROW(init_string_string());
}