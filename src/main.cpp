#include <iostream>
#include "separate_chaining_hashmap.h"

int main() {
    std::cout << "Hello world! " << std::endl;
    std::cout << "temp: " << temp(1,2) << std::endl;
    SeparateChainingHashMap<int, int> hmap(1002);

    hmap.print_something();

    return 0;
}