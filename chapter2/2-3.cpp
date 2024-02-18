#include "./linked_list.cpp"

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

  /* If middle_node is tail_, we can't solve this problem. In this case, we
   * should prepare for dummy node.*/

  void delete_middle(LinkedList::SinglyNode *middle_node) {
    LinkedList::SinglyNode *next = middle_node->get_next();
    middle_node->set_data(next->get_data());
    middle_node->set_next(next->get_next());
  }
};
} // namespace Solution
