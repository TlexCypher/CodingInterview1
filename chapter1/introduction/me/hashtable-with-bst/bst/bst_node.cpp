#include <iostream>
using namespace std;

namespace BST {
class Node {
private:
  string key_;
  string value_;
  Node *parent_;
  Node *left_;
  Node *right_;

public:
  Node() {
    key_ = "";
    value_ = "";
    parent_ = nullptr;
    left_ = nullptr;
    right_ = nullptr;
  }
  Node(string key, string value) {
    key_ = key;
    value_ = value;
    parent_ = nullptr;
    left_ = nullptr;
    right_ = nullptr;
  }

  string get_key() {
    return key_;
  }

  string get_value() {
    return value_;
  }

  Node* get_parent() {
    return parent_;
  }

  Node* get_left() {
    return left_;
  }

  Node* get_right() {
    return right_;
  }

  void set_key(string key) {
    key_ = key;
  }

  void set_value(string value) {
    value_ = value;
  }

  void set_parent(Node* parent) {
    parent_ = parent;
  }

  void set_left(Node* left) {
    left_ = left;
  }

  void set_right(Node* right) {
    right_ = right;
  }
};
} // namespace BST
