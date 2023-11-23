#include <iostream>
using namespace std;
/*
This file contains the implementation for a binary tree
-doesn't reinsert elements which are already in tree
-when a node with two children is deleted it's replaced by the max of the left subtree
-can print inorder
*/

struct Node {
  int value;
  Node *left;
  Node *right;
  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {

private:
  Node *root;

  // binary tree traversal
  Node *recursive_search(Node *node, int val) {
    // base case
    if (val == node->value)
      return node;

    // recursing
    else if (val > node->value && node->right != nullptr)
      return recursive_search(node->right, val);
    else if (val < node->value && node->left != nullptr)
      return recursive_search(node->left, val);

    return nullptr; // if reach end & not found
  }

  Node *recursive_insert(Node *node, int val) {
    // base case
    if (node == nullptr)
      return new Node(val);

    // recursing
    else if (val < node->value)
      node->left = recursive_insert(node->left, val);
    else if (val > node->value)
      node->right = recursive_insert(node->right, val);

    return node; // no action taken if duplicate
  }

  Node *recursive_remove(Node *node, int val) {
    //base case
    if (node == nullptr) return node;

    //recursing
    else if (val < node->value)
      node->left = recursive_remove(node->left, val);
    else if (val > node->value)
      node->right = recursive_remove(node->right, val);
    
    /* node found */
    else {
      // 0 children
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr; // return nullptr to parent's child pointer
      }
      //2 children (replace with max from left subtree)
      else if (node->left != nullptr && node->right != nullptr) {
        Node *max_left = node->left;
        while (max_left->right != nullptr)
          max_left = max_left->right;
        node->value = max_left->value;
        node->left = recursive_remove(node->left, max_left->value);
      }
      //1 child
      else {
        Node *temp = node;
        node = (node->left != nullptr) ? node->left : node->right;
        delete temp;
      }
    }
    return node;
  }

  // recusively traversing to free memory
  void recursive_destroy_tree(Node *node) {
    if (node == nullptr) return; // base case
    recursive_destroy_tree(node->left);
    recursive_destroy_tree(node->right);
    delete node;
    node = nullptr;
  }

  // recusively traversing to print inorder
  void recursive_inorder(Node *node) {
    if (node == nullptr) return; // base case
    recursive_inorder(node->left);
    cout << node->value << " ";
    recursive_inorder(node->right);
  }

public:
  BinaryTree() { root = nullptr; }
  ~BinaryTree() { recursive_destroy_tree(root); }

  // recursively searching using binary search
  bool search(int value) {
    if (root == nullptr) return false;
    return recursive_search(root, value) != nullptr;
  }

  // insertion & deletion
  void insert(int value) { root = recursive_insert(root, value); }
  void remove(int value) { root = recursive_remove(root, value); }

  //printing
  void print_inorder() {
    recursive_inorder(root);
    cout << endl;
  }
};

int main() {

  BinaryTree BT;

  //testing insertion
  BT.insert(1);
  BT.insert(1);
  BT.insert(2);
  BT.insert(3);
  BT.print_inorder();

  //testing removal
  BT.remove(2);
  BT.remove(3);
  BT.print_inorder();

  cout << "searching for 1: " << BT.search(1) << endl;
  cout << "searching for 4: " << BT.search(4) << endl;

  return 0;
}