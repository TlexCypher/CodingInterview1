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
  LinkedList::SinglyLinkedList *get_list() { return list_; }
  Solver(int capacity) { init(capacity); }

  int get_k_element(int k) {
    LinkedList::SinglyNode *ptr1 = list_->get_head();
    LinkedList::SinglyNode *ptr2 = list_->get_head();

    while (ptr2 != nullptr && k--) {
      ptr2 = ptr2->get_next();
    }

    if (k > 0) {
      printf("Length of linked-list is smaller than k.");
      return -1;
    }

    while (ptr2 != nullptr) {
      ptr1 = ptr1->get_next();
      ptr2 = ptr2->get_next();
    }

    return ptr1->get_data();
  }
};
} // namespace Solution

int main() {
  Solution::Solver *sol = new Solution::Solver(20);
  cout << sol->get_k_element(3) << endl;
  cout << sol->get_k_element(5) << endl;
}
