#include <iostream>

using namespace std;

namespace LinkedList {
class SinglyNode {
private:
  int data_;
  SinglyNode *next_;

public:
  SinglyNode() { next_ = nullptr; }
  SinglyNode(int data) {
    data_ = data;
    next_ = nullptr;
  }
  int get_data() { return data_; }
  void set_data(int data) { data_ = data; }
  SinglyNode *get_next() { return next_; }
  void set_next(SinglyNode *next) { next_ = next; }
};

class DoublyNode {
private:
  int data_;
  DoublyNode *next_;
  DoublyNode *prev_;

public:
  DoublyNode() {
    next_ = nullptr;
    prev_ = nullptr;
  }

  DoublyNode(int data) {
    data_ = data;
    next_ = nullptr;
    prev_ = nullptr;
  }

  int get_data() { return data_; }
  void set_data(int data) { data_ = data; }
  DoublyNode *get_next() { return next_; }
  void set_next(DoublyNode *next) { next_ = next; }
  DoublyNode *get_prev() { return prev_; }
  void set_prev(DoublyNode *prev) { prev_ = prev; }
};
} // namespace LinkedList
