#include<gtest/gtest.h>
#include "separate_chaining_hashmap.h"
#include <string>

TEST(Hashmap, InsertionAndFind) {
    SeparateChainingHashMap<std::string, int> hmap;
    hmap.insert("a", 1);
    EXPECT_EQ(hmap.contains("a"), 1);
}