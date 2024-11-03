#include <iostream>
#include "separate_chaining_hashmap.h"
#include<functional>
#include<memory>

int main() {
    SeparateChainingHashMap<std::string, int> hmap;
    hmap.insert("123", 1);
    hmap.insert("122", 123);
    hmap.insert("124", 2);
    hmap.insert("125", 2);
    hmap.insert("126", 1000);
    hmap.insert("123", 100);
    hmap.insert("126", 125);
    hmap.print();
    hmap.erase("124");
    hmap.erase("126");
    std::cout << "contains 124: " << hmap.contains("124") << std::endl;
    hmap.print();
    return 0;
}