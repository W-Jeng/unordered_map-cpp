#include <iostream>
#include "separate_chaining_hashmap.h"
#include<functional>
#include<memory>

int main() {
    SeparateChainingHashMap<std::string, int> hmap;
    hmap.insert("123", 1);
    hmap.insert("122", 2);
    hmap.insert("124", 2);
    hmap.insert("125", 2);
    hmap.insert("126", 1000);
    hmap.insert("123", 100);
    hmap.print();

    return 0;
}