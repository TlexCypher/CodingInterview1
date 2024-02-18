#include "./linked_list.cpp"
#include <stack>

namespace Solution {
class Solver {
public:
  bool is_palindrome(LinkedList::SinglyLinkedList *list) {
    LinkedList::SinglyNode *slow = list->get_head();
    LinkedList::SinglyNode *fast = list->get_head();
    stack<int> st;
    while (fast != nullptr) {
      st.push(slow->get_data());
      slow = slow->get_next();
      fast = fast->get_next()->get_next();
    }
    while (slow != nullptr) {
      if (st.empty()) {
        return false;
      }
      if (st.top() != slow->get_data()) {
        return false;
      }
      st.pop();
      slow = slow->get_next();
    }
    return st.empty();
  }
};
} // namespace Solution
