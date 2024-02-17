#include <iostream>

using namespace std;

namespace LinkedList {
class Node {
private:
  string key_;
  string value_;
  Node *next_;
  Node *prev_;

public:
  Node(){};
  Node(string key, string value)
      : key_(key), value_(value), next_(nullptr), prev_(nullptr){};
  Node(string key, string value, Node *next, Node *prev)
      : key_(key), value_(value), next_(next), prev_(prev){};
  void print_node() { cout << key_ << " " << value_ << endl; }

  string get_key() { return key_; }

  string get_value() { return value_; }

  Node *get_next() { return next_; }

  Node *get_prev() { return prev_; }

  void set_key(string key) { key_ = key; }

  void set_value(string value) { value_ = value; }

  void set_next(Node *next) { next_ = next; }

  void set_prev(Node *prev) { prev_ = prev; }
};
} // namespace LinkedList
