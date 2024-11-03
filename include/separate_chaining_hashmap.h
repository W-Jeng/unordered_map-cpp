#include<unordered_map>
#include<iostream>
#include<vector>
#include<memory>
#include<string>

int temp(int a, int b) {
    return a+b;
}

template <typename key_type, typename value_type>
class SeparateChainingHashMap {
private:

    struct Node {
        key_type key;
        value_type value;
        std::shared_ptr<Node> next = nullptr;

        Node(const key_type& k, const value_type& v): key(k), value(v) {}
    };

    size_t size{0};
    size_t bucket_size{16};
    const int resize_factor{2};
    const double load_factor{1.0}; 
    std::vector<std::shared_ptr<Node>> buckets; 
/*
    void traverse_insert(std::shared_ptr<Node>& bucket_linked_list,
        const key_type& inserting_key,
        const value_type& inserting_value) {
        
        std::shared_ptr<Node> current_node = bucket_linked_list;

        // tranverse to the end of pointer or when we found the key in the linked list
        while (current_node != nullptr) {
            if ((current_node -> key) == inserting_key) { std::cout << "found it at the node value, replacing!" << std::endl; current_node -> value = inserting_value; return; } // Check if the key already exists current_node = current_node->next; // Update current_node }

        current_node = std::make_shared<Node>(inserting_key, inserting_value);
        std::cout << "creating new node at null start" << std::endl;

        return;
    }
*/
    void traverse_insert(std::shared_ptr<Node>& bucket_linked_list,
        const key_type& inserting_key,
        const value_type& inserting_value) {
    
        std::shared_ptr<Node> current_node = bucket_linked_list;
        std::shared_ptr<Node> previous_node = nullptr;

        // Traverse the linked list to find the correct position
        while (current_node != nullptr) {
            if (current_node->key == inserting_key) {
                std::cout << "Found it at the node value, replacing!" << std::endl;
                current_node->value = inserting_value;
                return;  // Key found, update value and return
            }
            previous_node = current_node;
            current_node = current_node->next;  // Move to the next node
        }

        // Key not found, create a new node
        std::shared_ptr<Node> new_node = std::make_shared<Node>(inserting_key, inserting_value);
        std::cout << "Creating new node at the end of the list" << std::endl;

        // If the bucket is empty, set the new node as the head of the linked list
        if (bucket_linked_list == nullptr) {
            bucket_linked_list = new_node;
        } else {
            // Otherwise, append the new node at the end of the linked list
            previous_node -> next = new_node;
        }
    }

    void build_linked_list_repr(std::shared_ptr<Node>& bucket_linked_list,
        std::string& bucket_node_repr) {

        std::shared_ptr<Node> current_node = bucket_linked_list;

        while (current_node != nullptr) {
            bucket_node_repr += "->[" + current_node -> key + "," + std::to_string(current_node -> value)+"]";
            current_node = current_node -> next;
        }

        return;
    }

public:
    SeparateChainingHashMap(): buckets(bucket_size) {};
    
    void insert(const key_type& inserting_key, const value_type& inserting_value) {
        // hashing comes first, then we do some modulo
        size_t hashed_value = std::hash<key_type>{}(inserting_key) % bucket_size;
        std::cout << "hashed_value: " << hashed_value << std::endl;
        traverse_insert(buckets[hashed_value], inserting_key, inserting_value);
        return;
    }

    void print() {
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i] != nullptr) {
                std::string bucket_node_repr = "[HASHEDKEY=" + std::to_string(i) + "]";
                build_linked_list_repr(buckets[i], bucket_node_repr);
                std::cout << bucket_node_repr << std::endl;
            }
        }
        return;
    }
};