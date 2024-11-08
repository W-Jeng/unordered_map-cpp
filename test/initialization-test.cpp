#include<gtest/gtest.h>
#include "hashmap_rawptr.h"
#include "hashmap_sharedptr.h"
#include <string>

void init_string_int() {
    RawPtr::Hashmap<std::string, int> raw_hmap;
    SharedPtr::Hashmap<std::string, int> shared_hmap;
}

void init_int_int() {
    RawPtr::Hashmap<int, int> raw_hmap;
    SharedPtr::Hashmap<int, int> shared_hmap;
}

void init_double_int() {
    RawPtr::Hashmap<double, int> raw_hmap;
    SharedPtr::Hashmap<double, int> shared_hmap;
}

void init_int_string() {
    RawPtr::Hashmap<int, std::string> raw_hmap;
    SharedPtr::Hashmap<int, std::string> shared_hmap;
}

void init_string_string() {
    RawPtr::Hashmap<std::string, std::string> raw_hmap;
    SharedPtr::Hashmap<std::string, std::string> shared_hmap;
}

TEST(Hashmap, Initialization) {
    EXPECT_NO_THROW(init_string_int());
    EXPECT_NO_THROW(init_int_int());
    EXPECT_NO_THROW(init_double_int());
    EXPECT_NO_THROW(init_int_string());
    EXPECT_NO_THROW(init_string_string());
}