#include <iostream>
#include "separate_chaining_hashmap.h"
#include<functional>

int main() {
    std::cout << "Hello world! " << std::endl;
    std::cout << "temp: " << temp(1,2) << std::endl;
    std::cout << "hashing 133: " << std::hash<int>{}(133) << std::endl;
    std::cout << "hashing of hello: " << std::hash<std::string>{}("hello") << std::endl;
    SeparateChainingHashMap<std::string, int> hmap;
    hmap.insert("123", 1);

    hmap.print_something();

    return 0;
}