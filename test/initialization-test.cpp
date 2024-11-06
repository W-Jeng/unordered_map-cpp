#include<gtest/gtest.h>
#include "hashmap_sharedptr.h"
#include <string>

void init_string_int() {
    SharedPtr::Hashmap<std::string, int> hmap;
}

void init_int_int() {
    SharedPtr::Hashmap<int, int> hmap;
}

void init_double_int() {
    SharedPtr::Hashmap<double, int> hmap;
}

void init_int_string() {
    SharedPtr::Hashmap<int, std::string> hmap;
}

void init_string_string() {
    SharedPtr::Hashmap<std::string, std::string> hmap;
}

TEST(Hashmap, Initialization) {
    EXPECT_NO_THROW(init_string_int());
    EXPECT_NO_THROW(init_int_int());
    EXPECT_NO_THROW(init_double_int());
    EXPECT_NO_THROW(init_int_string());
    EXPECT_NO_THROW(init_string_string());
}