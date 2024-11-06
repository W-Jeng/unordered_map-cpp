#include<gtest/gtest.h>
#include "hashmap_sharedptr.h"
#include <string>

TEST(Hashmap, InsertionAndFind) {
    SharedPtr::Hashmap<std::string, int> hmap;
    hmap.insert("a", 1);
    EXPECT_EQ(hmap.contains("a"), 1);
}