#include "./linked_list.cpp"
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

/*
 * _HashTableWithLinkedList is hash-table with doubly linked list.
 *
 * This implementaion was done by me.
 *
 * In test.cpp, this will work well.
 * */

namespace HashTable {
class _HashTableWithLinkedList {
private:
  vector<LinkedList::LinkedList> value_list_;
  int32_t capacity_;
  int32_t hash_func(string data) {
    int32_t sum = 0;
    for (size_t itr = 0; itr < data.size(); itr++) {
      sum += data[itr];
      sum %= capacity_;
    }
    return sum;
  }

public:
  _HashTableWithLinkedList(int32_t capacity) {
    capacity_ = capacity;
    value_list_.resize(capacity);
  };

  void put(string key, string value) {
    int index = hash_func(key);
    value_list_[index].add_node(new LinkedList::Node(key, value));
  }

  string get(string key) {
    int index = hash_func(key);
    LinkedList::LinkedList *list = &value_list_[index];
    LinkedList::Node *ptr = list->get_head();
    while (ptr != nullptr) {
      if (ptr->get_key() == key) {
        return ptr->get_value();
      }
      ptr = ptr->get_next();
    }
    return "";
  }
};
} // namespace HashTable
