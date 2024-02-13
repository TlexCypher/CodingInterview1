#include "./node.cpp"

using namespace std;

/*
 * This class is Doubly LinkedList that would be used for the implementation of
 * HashTable.
 *
 * */

namespace LinkedList {
class LinkedList {
private:
  Node *head_;
  Node *tail_;

public:
  LinkedList() : head_(nullptr), tail_(nullptr){};
  LinkedList(Node *head, Node *tail) : head_(head), tail_(tail) {
    head_->set_next(tail_);
    tail_->set_prev(head_);
  }

  void add_node(Node *new_node) {
    if (head_ == nullptr) {
      head_ = new_node;
    } else if (tail_ == nullptr) {
      tail_ = new_node;
      head_->set_next(tail_);
      tail_->set_prev(head_);
    } else {
      Node *node = tail_;
      node->set_next(new_node);
      new_node->set_prev(node);
      tail_ = new_node;
    }
  }

  void delete_tail_node() {
    if (head_ == nullptr) {
      return;
    } else if (tail_ == nullptr) {
      head_ = nullptr;
    } else {
      Node *next_tail_node = tail_->get_prev();
      tail_->set_prev(nullptr);
      next_tail_node->set_next(nullptr);
      tail_ = next_tail_node;
    }
  }

  void walk() {
    Node *current_node = head_;
    while (current_node != nullptr) {
      current_node->print_node();
      current_node = current_node->get_next();
    }
  }

  Node *get_head() { return head_; }

  Node *get_tail() { return tail_; }

  void set_head(Node *head) { head_ = head; }

  void set_tail(Node *tail) { tail_ = tail; }
};
} // namespace LinkedList
