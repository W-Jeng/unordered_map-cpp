#include<gtest/gtest.h>
#include "separate_chaining_hashmap.h"
#include <string>

TEST(SeparateChainingHashmap, SizeTestBasic) {
    SeparateChainingHashMap<std::string, std::string> hashmap;
    EXPECT_EQ(hashmap.size(), 0);
    hashmap.insert("A", "1");
    EXPECT_EQ(hashmap.size(), 1);
    hashmap.insert("B", "1");
    EXPECT_EQ(hashmap.size(), 2);
}

TEST(SeparateChainingHashmap, SizeTestLoop) {
    SeparateChainingHashMap<int, std::string> hashmap;
    const size_t elements{1000}; 

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, std::to_string(i));
        EXPECT_EQ(hashmap.size(), i+1);
    }
}

TEST(SeparateChainingHashmap, SizeTestClear) {
    SeparateChainingHashMap<int, int> hashmap;
    const size_t elements(1000);

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, elements+i);
    }
    EXPECT_EQ(hashmap.size(), elements);
    hashmap.clear();
    EXPECT_EQ(hashmap.size(), 0);
}

TEST(SeparateChainingHashmap, SizeTestEraseProgress) {
    SeparateChainingHashMap<int, int> hashmap;
    const size_t elements(100);

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, elements+1);
        EXPECT_EQ(hashmap.size(), i+1);
    }

    for (int i = 0; i < elements; ++i) {
        hashmap.erase(i);
        EXPECT_EQ(hashmap.size(), elements-(i+1));
    }
}

TEST(SeparateChainingHashmap, SizeTestEraseEmpty) {
    SeparateChainingHashMap<int, int> hashmap;

    hashmap.insert(1, 100);
    EXPECT_EQ(hashmap.size(), 1);

    hashmap.erase(2);
    EXPECT_EQ(hashmap.size(), 1);
}