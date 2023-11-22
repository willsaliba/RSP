#include <iostream>
using namespace std;

struct Node {
  int value;
  Node *next;
  Node(int val, Node* nxt) : value(val), next(nxt) {}
};

class LinkedList {

private:
  Node* head;
  // Node* tail;

public:
  LinkedList() {
    this->head = nullptr;
    // this->tail = nullptr;
  }

  ~LinkedList() {
    if (head != nullptr) return;

    Node* currNode = this->head;
    while (currNode != nullptr) {
      Node* nextNode = currNode->next;
      delete currNode;
      currNode = nextNode;
    }
  }

  Node *search(int value);

  void insert(int value) {
    
    Node* new_node = new Node(value, nullptr);

    if (head == nullptr) {
      //if emply list just point head to new_node
      this->head = new_node;
    } else {
      //new_node points to previous head & new_node becomes head
      new_node->next = this->head;
      this->head = new_node;
    }

  }

  void remove(int value);

  void print_list() {
    //empty list
    if (this->head == nullptr) {
      cout << "empty list" << endl;
      return;
    }

    //else print whole list
    Node* currNode = this->head;
    cout << "head";
    while (currNode != nullptr) {
      cout << "->" << currNode->value << endl;
      currNode = currNode->next;
    }
  };
};



int main() {

  LinkedList ll;

  ll.print_list();
  
  ll.insert(5);
  ll.insert(4);
  ll.insert(3);

  ll.print_list();

  return 0;
}