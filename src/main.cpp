#include <iostream>
#include "hashmap_sharedptr.h"
#include<functional>
#include<memory>

int main() {
    SharedPtr::Hashmap<std::string, int> hmap;
    hmap.insert("123", 1);
    hmap.insert("122", 123);
    hmap.insert("124", 2);
    hmap.insert("125", 2);
    hmap.insert("126", 1000);
    hmap.insert("123", 100);
    hmap.insert("126", 125);
    std::cout << "contains 124: " << hmap.contains("124") << std::endl;
    hmap.print();
    std::cout << "---------------------------" << std::endl;
    hmap.print();
    return 0;
}