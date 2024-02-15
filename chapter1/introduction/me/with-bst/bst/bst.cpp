#include "./bst_node.cpp"

namespace BST {
class BST {
private:
  Node* root_;

  string search_helper(Node* current_node, string &key) {
    if(current_node == nullptr) return "";
    string current_key = current_node->get_key();
    if(current_key == key) return current_node->get_value();
    else if(current_key >= key) return search_helper(current_node->get_left(), key);
    else return search_helper(current_node->get_right(), key);
  }

  void add_node_helper(Node* current_node, Node* new_node) {
    string current_key = current_node->get_key();
    Node* left_node = current_node->get_left();
    Node* right_node = current_node->get_right();
    Node* parent_node = current_node->get_parent();

    if(current_key >= new_node->get_key()) {
      if(left_node == nullptr) {
        current_node->set_left(new_node);
        new_node->set_parent(current_node);
      } else add_node_helper(left_node, new_node);
      
    } else {
      if(right_node == nullptr) {
        current_node->set_right(new_node);
        new_node->set_parent(current_node);
      } else add_node_helper(right_node, new_node);
    }
  }

public:
  BST() {
    root_ = nullptr;
  }
  BST(Node* root) {
    root_ = root;
  }

  void add_node(Node* new_node) {
    if(root_ == nullptr) {
      root_ = new_node;
      return;
    }
    add_node_helper(root_, new_node);
  } 

  string search(string &key) {
    return search_helper(root_, key);
  }
};
}
