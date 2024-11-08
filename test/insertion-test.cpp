#include<gtest/gtest.h>
#include "hashmap_rawptr.h"
#include "hashmap_sharedptr.h"
#include <string>

bool char_is_in(const std::string& lookup_chars, char lookup_val) {
    for (int i = 0; i < lookup_chars.size(); ++i) {
        if (lookup_chars[i] == lookup_val) {
            return true;
        }
    }
    return false;
}

TEST(RawPtrHashmap, InsertionTest) {
    RawPtr::Hashmap<int, int> hashmap;
    hashmap.insert(1, 101);
    hashmap.insert(2, 102);
    EXPECT_TRUE(hashmap.contains(1));
    EXPECT_TRUE(hashmap.contains(2));
    EXPECT_FALSE(hashmap.contains(3));
    EXPECT_FALSE(hashmap.contains(4));    
}

TEST(RawPtrHashmap, InsertionTestWithDeletion) {
    RawPtr::Hashmap<std::string, int> hashmap;

    for (int i = 0; i < 26; ++i) {
        std::string temp = std::string(1, 'a'+i);
        hashmap.insert(temp, i);
    }

    for (int i = 0; i < 26; ++i) {
        std::string temp = std::string(1, 'a'+i);
        EXPECT_TRUE(hashmap.contains(temp));
    }

    std::string char_to_remove = "qwertyuiop";
    for (int i = 0; i < char_to_remove.size(); ++i) {
        hashmap.erase(std::string(1, char_to_remove[i]));
    }

    // test on all alphabets except where we expect false
    for (int i = 0; i < 26; ++i) {
        char temp = 'a' + i;
        if (char_is_in(char_to_remove, temp)) {
            EXPECT_FALSE(hashmap.contains(std::string(1, temp)));
        } else {
            EXPECT_TRUE(hashmap.contains(std::string(1, temp)));
        }
    }
}

TEST(RawPtrHashmap, InsertionTestWithClear) {
    RawPtr::Hashmap<int, int> hashmap;
    const size_t elements = 1000;

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, elements+i);
    }
    
    for (int i = 0; i < elements; ++i) {
        EXPECT_TRUE(hashmap.contains(i));
    }

    hashmap.clear();

    for (int i = 0; i < elements; ++i) {
        EXPECT_FALSE(hashmap.contains(i));
    }
}

TEST(RawPtrHashmap, InsertionTestWithAt) {
    RawPtr::Hashmap<size_t, size_t> hashmap;
    const size_t elements = 100;

    for (int i = 0; i < elements; ++i) {
        size_t hashed_key = std::hash<size_t>{}(i);
        size_t hashed_value = std::hash<size_t>{}(i+elements);
        hashmap.insert(hashed_key, hashed_value);
    }

    for (int i = 0; i < elements; ++i) {
        EXPECT_EQ(hashmap.at(std::hash<size_t>{}(i)), std::hash<size_t>{}(i+elements));
    }
}

TEST(SharedPtrHashmap, InsertionTest) {
    SharedPtr::Hashmap<int, int> hashmap;
    hashmap.insert(1, 101);
    hashmap.insert(2, 102);
    EXPECT_TRUE(hashmap.contains(1));
    EXPECT_TRUE(hashmap.contains(2));
    EXPECT_FALSE(hashmap.contains(3));
    EXPECT_FALSE(hashmap.contains(4));    
}

TEST(SharedPtrHashmap, InsertionTestWithDeletion) {
    SharedPtr::Hashmap<std::string, int> hashmap;

    for (int i = 0; i < 26; ++i) {
        std::string temp = std::string(1, 'a'+i);
        hashmap.insert(temp, i);
    }

    for (int i = 0; i < 26; ++i) {
        std::string temp = std::string(1, 'a'+i);
        EXPECT_TRUE(hashmap.contains(temp));
    }

    std::string char_to_remove = "qwertyuiop";
    for (int i = 0; i < char_to_remove.size(); ++i) {
        hashmap.erase(std::string(1, char_to_remove[i]));
    }

    // test on all alphabets except where we expect false
    for (int i = 0; i < 26; ++i) {
        char temp = 'a' + i;
        if (char_is_in(char_to_remove, temp)) {
            EXPECT_FALSE(hashmap.contains(std::string(1, temp)));
        } else {
            EXPECT_TRUE(hashmap.contains(std::string(1, temp)));
        }
    }
}

TEST(SharedPtrHashmap, InsertionTestWithClear) {
    SharedPtr::Hashmap<int, int> hashmap;
    const size_t elements = 1000;

    for (int i = 0; i < elements; ++i) {
        hashmap.insert(i, elements+i);
    }
    
    for (int i = 0; i < elements; ++i) {
        EXPECT_TRUE(hashmap.contains(i));
    }

    hashmap.clear();

    for (int i = 0; i < elements; ++i) {
        EXPECT_FALSE(hashmap.contains(i));
    }
}

TEST(SharedPtrHashmap, InsertionTestWithAt) {
    SharedPtr::Hashmap<size_t, size_t> hashmap;
    const size_t elements = 100;

    for (int i = 0; i < elements; ++i) {
        size_t hashed_key = std::hash<size_t>{}(i);
        size_t hashed_value = std::hash<size_t>{}(i+elements);
        hashmap.insert(hashed_key, hashed_value);
    }

    for (int i = 0; i < elements; ++i) {
        EXPECT_EQ(hashmap.at(std::hash<size_t>{}(i)), std::hash<size_t>{}(i+elements));
    }
}
