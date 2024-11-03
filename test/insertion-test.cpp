#include<gtest/gtest.h>
#include "separate_chaining_hashmap.h"
#include <string>

TEST(SeparateChainingHashmap, InsertionTest) {
    SeparateChainingHashMap<int, int> hashmap;
    hashmap.insert(1, 101);
    hashmap.insert(2, 102);
    EXPECT_TRUE(hashmap.contains(1));
    EXPECT_TRUE(hashmap.contains(2));
    EXPECT_FALSE(hashmap.contains(3));
    EXPECT_FALSE(hashmap.contains(4));    
}

bool char_is_in(const std::string& lookup_chars, char lookup_val) {
    for (int i = 0; i < lookup_chars.size(); ++i) {
        if (lookup_chars[i] == lookup_val) {
            return true;
        }
    }
    return false;
}

TEST(SeparateChainingHashmap, InsertionTestWithDeletion) {
    SeparateChainingHashMap<std::string, int> hashmap;

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

TEST(SeparateChainingHashmap, InsertionTestWithClear) {
    SeparateChainingHashMap<int, int> hashmap;
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

