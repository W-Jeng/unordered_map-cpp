#include<unordered_map>
#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<stdexcept>

/*
    Implementation of hashmap
    Aim on functionalities:
        (void) insert
        (bool) contains
        (void) erase
        (value_type&) at 
        (std::string) print 
        (size_t) size()
        (void) clear, removes all element
        TODO (void) resize, rehash the whole structure with new buckets
*/
template <typename key_type, typename value_type>
class SeparateChainingHashMap {
private:

    struct Node {
        key_type key;
        value_type value;
        std::shared_ptr<Node> next = nullptr;

        Node(const key_type& k, const value_type& v): key(k), value(v) {}
    };

    const int resize_factor{2};
    const double load_factor{1.0}; 
    const size_t initial_bucket_size{16};
    size_t element_size{0};
    size_t bucket_size{initial_bucket_size};
    std::vector<std::shared_ptr<Node>> buckets; 

    void traverse_insert(std::shared_ptr<Node>& bucket_linked_list,
        const key_type& inserting_key,
        const value_type& inserting_value) {
        
        std::shared_ptr<Node> current_node = bucket_linked_list;
        std::shared_ptr<Node> previous_node = nullptr;

        // Traverse the linked list to find the correct position
        while (current_node != nullptr) {
            if (current_node->key == inserting_key) {
                current_node->value = inserting_value;
                return;  // Key found, update value and return
            }
            previous_node = current_node;
            current_node = current_node->next; 
        }

        // Key not found, create a new node
        std::shared_ptr<Node> new_node = std::make_shared<Node>(inserting_key, inserting_value);

        // If the bucket is empty, set the new node as the head of the linked list
        element_size++;
        if (bucket_linked_list == nullptr) {
            bucket_linked_list = new_node;
        } else {
            previous_node -> next = new_node;
        }
        return;
    }

    void build_linked_list_repr(std::shared_ptr<Node>& bucket_linked_list,
        std::string& bucket_node_repr) {

        std::shared_ptr<Node> current_node = bucket_linked_list;
        while (current_node != nullptr) {
            bucket_node_repr += "->[" + current_node -> key +
                "," + std::to_string(current_node -> value)+"]";
            current_node = current_node -> next;
        }
        return;
    }

    void traverse_remove(std::shared_ptr<Node>& bucket_linked_list,
        const key_type& removal_key) {
        
        if (bucket_linked_list == nullptr) {
            return;
        }

        std::shared_ptr<Node> current_node = bucket_linked_list; 
        std::shared_ptr<Node> previous_node = nullptr;

        while (current_node != nullptr) {
            if (current_node -> key == removal_key) {
                if (previous_node == nullptr) {
                    // removal at head
                    bucket_linked_list = current_node -> next;       
                } else {
                    // skipping this node == deleting it
                    previous_node -> next = current_node -> next;
                }
                element_size--;
                return;
            }
            previous_node = current_node;
            current_node = current_node -> next;
        }
        return;
    }

public:
    SeparateChainingHashMap(): buckets(bucket_size) {};
    
    void insert(const key_type& inserting_key, const value_type& inserting_value) {
        // hashing comes first, then we do some modulo
        size_t bucket_index = std::hash<key_type>{}(inserting_key) % bucket_size;
        traverse_insert(buckets[bucket_index], inserting_key, inserting_value);
        return;
    }

    value_type& at(const key_type& lookup_key) const {
        size_t bucket_index = std::hash<key_type>{}(lookup_key) % bucket_size;
        std::shared_ptr<Node> current_node = buckets[bucket_index];

        while (current_node != nullptr && (current_node -> key != lookup_key)) {
            current_node = current_node -> next;
        }

        if (current_node != nullptr) {
            return current_node -> value;
        }

        throw std::out_of_range("Key not found");
    }

    bool contains(const key_type& lookup_key) const {
        size_t bucket_index = std::hash<key_type>{}(lookup_key) % bucket_size;
        std::shared_ptr<Node> current_node = buckets[bucket_index];

        while (current_node != nullptr) {
            if ((current_node -> key) == lookup_key) {
                return true;
            }
            current_node = current_node -> next;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i] == nullptr) {
                continue;
            }
            std::string bucket_node_repr = "[HASHEDKEY=" + std::to_string(i) + "]";
            build_linked_list_repr(buckets[i], bucket_node_repr);
            std::cout << bucket_node_repr << std::endl;
        }
        return;
    }

    void clear() {
        buckets.assign(initial_bucket_size, nullptr);
        bucket_size = initial_bucket_size;
        element_size = 0;
        return;
    }

    void erase(const key_type& removal_key) {
        size_t bucket_index = std::hash<key_type>{}(removal_key) % bucket_size;
        traverse_remove(buckets[bucket_index], removal_key);
        return;
    }

    size_t size() {
        return element_size;
    }
};