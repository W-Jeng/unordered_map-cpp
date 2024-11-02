#include<unordered_map>
#include<iostream>
#include<vector>
#include<memory>

int temp(int a, int b) {
    return a+b;
}

template <typename key_type, typename value_type>
class SeparateChainingHashMap {
private:

    struct Node {
        key_type key;
        value_type value;
        Node* next = nullptr;

        Node(const key_type& k, const value_type& v): key(k), value(v) {}
    };

    size_t size{0};
    size_t buckets{16};
    const int resize_factor{2};
    const double load_factor{1.0}; 
    std::vector<std::unique_ptr<Node>> bucket_nodes; 

public:
    SeparateChainingHashMap(): bucket_nodes(buckets) {};
    
    void insert(const key_type& key, const value_type& value) {
        // hashing comes first, then we do some modulo
        size_t hashed_value = std::hash<key_type>{}(key) % buckets;

        if (bucket_nodes[hashed_value] == nullptr) {
            bucket_nodes[hashed_value] = std::make_unique<Node>(key, value);
        } else {
            // TODO 2
            continue;
        }
        std::cout << "hashed value: " << hashed_value % buckets << std::endl;

        return;
    }

    void print_something() {
        std::cout << "hello world!" << std::endl;
        return;
    }
};