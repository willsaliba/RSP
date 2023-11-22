#include <iostream>
using namespace std;
/*
This file contains the implementation for a binary tree
-doesn't allow duplicate elements to be inserted
*/

struct Node {
  int value;
  Node *left;
  Node *right;
  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {

private:
  Node* root;

  Node* recursive_search(Node* currNode, int val) {
    if (currNode->value == val) return currNode;
    else if (val < currNode->value && currNode->left != nullptr) return recursive_search(currNode->left, val);
    else if (val > currNode->value && currNode->right != nullptr) return recursive_search(currNode->right, val);
    else return nullptr;
  }

  void recursive_insert(Node* currNode, int val) {
    //if element already in tree do nothing
    if (currNode->value == val) return;
    //if val < node & left subtree empty insert else recurse left
    else if (val < currNode->value) {
      if (currNode->left == nullptr) {
        Node* new_node = new Node(val);
        currNode->left = new_node;
      } else {
        recursive_insert(currNode->left, val);
      }
    }
    //if val > node & right subtree empty insert else recurse right
    else if (val > currNode->value) {
      if (currNode->right == nullptr) {
        Node* new_node = new Node(val);
        currNode->right = new_node;
      } else {
        recursive_insert(currNode->right, val);
      }
    }
  }

  //maybe suss adsa
  void recursive_remove(Node* currNode, int val) {

  }

public:

  Node* search(int val) {
    Node* currNode = this->root;
    return recursive_search(currNode, val);
  }

  void insert(int val) {
    Node* currNode = this->root;
    //if tree empty
    if (currNode == nullptr) {
      Node* new_node = new Node(val);
      this->root = new_node;
    } else {
      //recurse to insert at correct position
      recursive_insert(currNode, val);
    }
  }

  void remove(int val) {
    Node* currNode = this->root;
    //if tree empty do nothing
    if (currNode == nullptr) return;

    //if deleting root
    if (currNode->value == val) {
      
    }

    //else recurse to correct position
    else recursive_remove(currNode, val);
  }

  void print_tree() {
    if (this->root == nullptr) cout << "tree empty" << endl;
    else {
      cout << "tree hahah" << endl;
    }
  }
};