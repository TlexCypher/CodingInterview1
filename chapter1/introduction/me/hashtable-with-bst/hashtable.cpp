#include "./bst/bst.cpp"
#include <vector>

namespace HashTable {
class HashTable {
private:
  int32_t capacity_;
  vector<BST::BST> arr_;

  int32_t hash_func(string value) {
    int32_t index = 0;
    for (size_t itr = 0; itr < value.size(); itr++) {
      index += value[itr];
      index %= capacity_;
    }
    return index;
  }

public:
  HashTable() {}
  HashTable(int32_t capacity) {
    capacity_ = capacity;
    arr_.resize(capacity);
  }

  void put(string key, string value) {
    int32_t index = hash_func(key);
    arr_[index].add_node(new BST::Node(key, value));
  }

  string get(string key) {
    int32_t index = hash_func(key);
    return arr_[index].search(key);
  }
};
} // namespace HashTable
