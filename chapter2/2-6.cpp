#include "./linked_list.cpp"

namespace Solution {
class Solver {
public:
  LinkedList::SinglyNode *
  detect_loop_start(LinkedList::SinglyLinkedList *list) {
    LinkedList::SinglyNode *slow = list->get_head();
    LinkedList::SinglyNode *fast = list->get_head();
    int loop_length = 0;
    while (slow != fast) {
      slow = slow->get_next();
      fast = fast->get_next()->get_next();
      loop_length++;
    }
    slow = list->get_head();
    while (slow != fast) {
      slow = slow->get_next();
      fast = fast->get_next();
    }
    return slow;
  }
};
} // namespace Solution
