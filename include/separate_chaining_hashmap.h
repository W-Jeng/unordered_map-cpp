#include<unordered_map>
#include<iostream>
#include<vector>

int temp(int a, int b) {
    return a+b;
}

template <typename _key, typename _value>
class SeparateChainingHashMap {
private:
    size_t size{0};
    size_t buckets{16};
    const int resize_factor{2};
    const double load_factor{1.0}; 
    std::vector<int> bucket_nodes; 


    struct Node {
        _key key;
        _value value;
        Node* next = nullptr;

        Node(const _key& k, const _value& v): key(k), value(v) {}
    };

public:
    SeparateChainingHashMap(){}

    void print_something() {
        std::cout << "hello world!" << std::endl;
        return;
    }
};