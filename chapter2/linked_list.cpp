#include "./node.cpp"
#include <stack>

using namespace std;

namespace LinkedList {
class SinglyLinkedList {
private:
  SinglyNode *head_;
  SinglyNode *tail_;

public:
  SinglyLinkedList() {}
  SinglyLinkedList(SinglyNode *node) { head_ = node; }
  SinglyLinkedList(int data) { head_ = new SinglyNode(data); }

  void add_node(int data) {
    if (head_ == nullptr) {
      set_head(new SinglyNode(data));
    } else if (tail_ == nullptr) {
      set_tail(new SinglyNode(data));
      head_->set_next(tail_);
    } else {
      SinglyNode *current_tail = tail_;
      SinglyNode *new_node = new SinglyNode(data);
      current_tail->set_next(new_node);
      set_tail(new_node);
    }
  }

  void delete_node(SinglyNode *node) {
    if (node == head_) {
      head_ = node->get_next();
    } else if (node == tail_) {
      SinglyNode *prev = head_;
      while (prev->get_next() != node) {
        prev = prev->get_next();
      }
      prev->set_next(nullptr);
      set_tail(prev);
    } else {
      SinglyNode *prev = head_;
      while (prev->get_next() != node) {
        prev = prev->get_next();
      }
      SinglyNode *next = node->get_next();
      prev->set_next(next);
    }
  }

  void walk() {
    SinglyNode *node = head_;
    while (node != nullptr) {
      printf("%d\n", node->get_data());
      node = node->get_next();
    }
  }

  void reverse_walk() {
    stack<int> s;
    SinglyNode *node = head_;
    while (node != nullptr) {
      s.push(node->get_data());
      node = node->get_next();
    }
    while (!s.empty()) {
      int v = s.top();
      s.pop();
      printf("%d\n", v);
    }
  }

  SinglyNode *get_head() { return head_; }
  SinglyNode *get_tail() { return tail_; }
  void set_head(SinglyNode *node) { head_ = node; }
  void set_tail(SinglyNode *node) { tail_ = node; }
};

class DoublyLinkedList {
private:
  DoublyNode *head_;
  DoublyNode *tail_;

public:
  DoublyLinkedList() {}
  DoublyLinkedList(DoublyNode *node) { head_ = node; }
  DoublyLinkedList(int data) { head_ = new DoublyNode(data); }

  void add_node(int data) {
    DoublyNode *new_node = new DoublyNode(data);
    if (head_ == nullptr) {
      set_head(new_node);
    } else if (tail_ == nullptr) {
      set_tail(new_node);
      head_->set_next(tail_);
      tail_->set_prev(head_);
    } else {
      DoublyNode *current_tail = tail_;
      current_tail->set_next(new_node);
      new_node->set_prev(current_tail);
      set_tail(new_node);
    }
  }

  void delete_node(DoublyNode *node) {
    if (node == head_) {
      set_head(head_->get_next());
    } else if (node == tail_) {
      set_tail(tail_->get_prev());
      tail_->set_next(nullptr);
    } else {
      DoublyNode *next = node->get_next();
      DoublyNode *prev = node->get_prev();
      prev->set_next(next);
      next->set_prev(prev);
    }
  }

  void walk() {
    DoublyNode *node = head_;
    while (node != nullptr) {
      printf("%d\n", node->get_data());
      node = node->get_next();
    }
  }

  DoublyNode *get_head() { return head_; }
  DoublyNode *get_tail() { return tail_; }
  void set_head(DoublyNode *node) { head_ = node; }
  void set_tail(DoublyNode *node) { tail_ = node; }
};
} // namespace LinkedList
