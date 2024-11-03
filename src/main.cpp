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
    std::cout << hmap.at("123") << std::endl;
    std::cout << hmap.contains("123") << std::endl;
    std::cout << "size of hmap: " << hmap.size() << std::endl;
    hmap.print();
    hmap.clear();
    std::cout << "cleared!" << std::endl;
    hmap.insert("1", 2);
    hmap.print();
    return 0;
}