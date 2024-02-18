#include "./linked_list.cpp"

using namespace std;

namespace Solution {
class Solver {
private:
  LinkedList::SinglyLinkedList *list_;

  void init(int capacity) {
    list_ = new LinkedList::SinglyLinkedList();
    for (int i = 0; i < capacity; i++) {
      int val = i % 10 + 1;
      list_->add_node(val);
    }
  }

public:
  Solver(int capacity) { init(capacity); }

  LinkedList::SinglyLinkedList *reorder_with_border(int border) {
    LinkedList::SinglyLinkedList *front = new LinkedList::SinglyLinkedList();
    LinkedList::SinglyLinkedList *back = new LinkedList::SinglyLinkedList();
    LinkedList::SinglyNode *current = list_->get_head();

    while (current != nullptr) {
      if (current->get_data() <= border) {
        front->add_node(current->get_data());
      } else {
        back->add_node(current->get_data());
      }
      current = current->get_next();
    }
    front->get_tail()->set_next(back->get_head());
    return front;
  }
};
} // namespace Solution

int main() {
  Solution::Solver *sol = new Solution::Solver(20);
  LinkedList::SinglyLinkedList *list = sol->reorder_with_border(3);
  list->walk();
}
