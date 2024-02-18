#include "./linked_list.cpp"
#include <algorithm>
#include <vector>

using namespace std;

namespace Solution {
class Solver {
private:
  LinkedList::SinglyLinkedList *list1_;
  LinkedList::SinglyLinkedList *list2_;
  int n_;
  int m_;

  void init(vector<int> &num1, vector<int> &num2) {

    list1_ = new LinkedList::SinglyLinkedList();
    list2_ = new LinkedList::SinglyLinkedList();

    n_ = (int)num1.size();
    m_ = (int)num2.size();

    for (int i = 0; i < n_; i++) {
      list1_->add_node(num1[i]);
    }

    for (int i = 0; i < m_; i++) {
      list2_->add_node(num2[i]);
    }
  }

public:
  Solver(vector<int> num1, vector<int> num2) { init(num1, num2); }
  LinkedList::SinglyLinkedList *add_linked_list_reverse() {
    int l = min(n_, m_);
    LinkedList::SinglyNode *node1 = list1_->get_head();
    LinkedList::SinglyNode *node2 = list2_->get_head();
    LinkedList::SinglyLinkedList *ans_list = new LinkedList::SinglyLinkedList();
    int carry_up = 0;
    for (int i = 0; i < l; i++) {
      int sum = node1->get_data() + node2->get_data() + carry_up;
      int nd = sum % 10;
      carry_up = sum / 10;
      ans_list->add_node(nd);
      node1 = node1->get_next();
      node2 = node2->get_next();
    }

    if (m_ > n_) {
      swap(n_, m_);
      swap(list1_, list2_);
      swap(node1, node2);
    }
    int dif = n_ - m_;
    for (int i = 0; i < dif; i++) {
      int sum = node1->get_data() + carry_up;
      int nd = sum % 10;
      carry_up = sum / 10;
      ans_list->add_node(nd);
    }
    return ans_list;
  }

  LinkedList::SinglyLinkedList *add_linked_list() {}
};
} // namespace Solution

int main() {
  vector<int> num1 = vector<int>{7, 1, 6};
  vector<int> num2 = vector<int>{0, 0, 9, 1};
  Solution::Solver *sol = new Solution::Solver(num1, num2);
  LinkedList::SinglyLinkedList *ans = sol->add_linked_list_reverse();
  ans->reverse_walk();
}
