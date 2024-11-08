#include<gtest/gtest.h>
#include "hashmap_sharedptr.h"
#include "hashmap_rawptr.h"
#include <string>

TEST(SharedPtrHashmap, SizeTestBasic) {
    SharedPtr::Hashmap<std::string, std::string> hashmap;
    EXPECT_EQ(hashmap.size(), 0);
    hashmap.insert("A", "1");
    EXPECT_EQ(hashmap.size(), 1);
    hashmap.insert("B", "1");
    EXPECT_EQ(hashmap.size(), 2);
}

TEST(SharedPtrHashmap, SizeTestLoop) {
    SharedPtr::Hashmap<int, std::string> hashmap;
    const size_t elements{100}; 

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, std::to_string(i));
        EXPECT_EQ(hashmap.size(), i+1);
    }
}

TEST(SharedPtrHashmap, SizeTestClear) {
    SharedPtr::Hashmap<int, int> hashmap;
    const size_t elements(100);

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, elements+i);
    }
    EXPECT_EQ(hashmap.size(), elements);
    hashmap.clear();
    EXPECT_EQ(hashmap.size(), 0);
}

TEST(SharedPtrHashmap, SizeTestEraseProgress) {
    SharedPtr::Hashmap<int, int> hashmap;
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

TEST(SharedPtrHashmap, SizeTestEraseEmpty) {
    SharedPtr::Hashmap<int, int> hashmap;

    hashmap.insert(1, 100);
    EXPECT_EQ(hashmap.size(), 1);

    hashmap.erase(2);
    EXPECT_EQ(hashmap.size(), 1);
}

TEST(RawPtrHashmap, SizeTestBasic) {
    RawPtr::Hashmap<std::string, std::string> hashmap;
    EXPECT_EQ(hashmap.size(), 0);
    hashmap.insert("A", "1");
    EXPECT_EQ(hashmap.size(), 1);
    hashmap.insert("B", "1");
    EXPECT_EQ(hashmap.size(), 2);
}

TEST(RawPtrHashmap, SizeTestLoop) {
    RawPtr::Hashmap<int, std::string> hashmap;
    const size_t elements{100}; 

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, std::to_string(i));
        EXPECT_EQ(hashmap.size(), i+1);
    }
}

TEST(RawPtrHashmap, SizeTestClear) {
    RawPtr::Hashmap<int, int> hashmap;
    const size_t elements(100);

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, elements+i);
    }
    EXPECT_EQ(hashmap.size(), elements);
    hashmap.clear();
    EXPECT_EQ(hashmap.size(), 0);
}

TEST(RawPtrHashmap, SizeTestEraseProgress) {
    RawPtr::Hashmap<int, int> hashmap;
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

TEST(RawPtrHashmap, SizeTestEraseEmpty) {
    RawPtr::Hashmap<int, int> hashmap;

    hashmap.insert(1, 100);
    EXPECT_EQ(hashmap.size(), 1);

    hashmap.erase(2);
    EXPECT_EQ(hashmap.size(), 1);
}