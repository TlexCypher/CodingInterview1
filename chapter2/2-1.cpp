#include "./linked_list.cpp"
#include <set>

using namespace std;

namespace Solution {
class Solver {
private:
  LinkedList::SinglyLinkedList *list_;

  void init(int capacity) {
    list_ = new LinkedList::SinglyLinkedList();
    for (int i = 0; i < capacity; i++) {
      int val = i % 4 + 1;
      list_->add_node(val);
    }
  }

public:
  Solver(int capacity) { init(capacity); }
  void take_unique() {
    set<int> st;
    LinkedList::SinglyNode *node = list_->get_head();
    while (node != nullptr) {
      if (st.count(node->get_data())) {
        list_->delete_node(node);
      }
      st.insert(node->get_data());
      node = node->get_next();
    }
  }

  LinkedList::SinglyLinkedList *get_list() { return list_; }
};
} // namespace Solution

int main() {
  Solution::Solver *sol = new Solution::Solver(20);
  sol->take_unique();
  sol->get_list()->walk();
}
