#include<unordered_map>
#include<iostream>

int temp(int a, int b) {
    return a+b;
}
template <typename _key, typename _value>
class SeparateChainingHashMap {
private:
    size_t size = 0;
    int abcd = 0;

    struct Node {
        _key key;
        _value value;
        Node* next = nullptr;

        Node(const _key& k, const _value& v): key(k), value(v) {}
    };

public:
    SeparateChainingHashMap(const int t_abcd): abcd(t_abcd) {}

    void print_something() {
        std::cout << "the value abcd is : " << abcd << std::endl;
        return;
    }
};