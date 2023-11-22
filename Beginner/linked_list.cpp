#include <iostream>
using namespace std;

/*
This file contains the implementation for a linked list which:
-inserts elements at the head O(1)
-allows multiple insertions of the same element
(removing element of which there are multiple results in most recently inserted one being removed)
*/

struct Node {
  int value;
  Node *next;
  Node(int val, Node* nxt) : value(val), next(nxt) {}
};

class LinkedList {

private:
  Node* head;

public:
  LinkedList() {
    this->head = nullptr;
  }

  ~LinkedList() {
    //freeing memory
    Node* currNode = this->head;
    while (currNode != nullptr) {
      Node* nextNode = currNode->next;
      delete currNode;
      currNode = nextNode;
    }
  }

  Node* search(int val) { // O(n)
    Node* currNode = this->head;
    //loop till end of list or find value
    while (currNode != nullptr && currNode->value != val) {
      currNode = currNode->next;
    }
    return currNode;
  }

  void insert(int val) { // O(1)
    Node* new_node = new Node(val, nullptr);
    //new_node points to previous head if list not empty
    if (this->head != nullptr) new_node->next = this->head;
    //new_node always inserted at head of list
    this->head = new_node;
  }

  void remove(int val) { // O(n)
    //checking for empty list
    if (this->head == nullptr) return;
    //if node to delete is at head
    Node* currNode = this->head;
    if (currNode->value == val) {
      this->head = currNode->next;
      delete currNode;
      return;
    } 
    //otherwise iterate through list to find it
    Node* before = currNode;
    currNode = currNode->next;
    while (currNode != nullptr && currNode->value != val) {
      before = currNode;
      currNode = currNode->next;
    }
    //if find node before reaching end of list
    if (currNode != nullptr) {
      before->next = currNode->next;
      delete currNode;
    }
  }

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
      cout << "->" << currNode->value;
      currNode = currNode->next;
    }
    cout << endl; //new line for my OCD
  };
};



/*
main function for testing functionality
*/
int main() {

  LinkedList ll;

  //testing intialisation
  cout << "--Intialising--" << endl;
  ll.print_list();
  
  //testing insertion
  cout << "\n--Inserting--" << endl;
  ll.insert(5);
  ll.insert(4);
  ll.insert(3);
  ll.insert(2);
  ll.insert(1);
  ll.print_list();

  //testing searching
  cout << "\n--Searching--" << endl;
  Node* node1 = ll.search(5);
  if (node1 != nullptr) cout << "found 5" << endl;
  else cout << "didnt find 5" << endl;

  Node* node2 = ll.search(6);
  if (node2 != nullptr) cout << "found 6" << endl;
  else cout << "didnt find 6" << endl;

  //testing removing
  cout << "\n--Removing--" << endl;
  ll.remove(6);
  ll.remove(5);
  ll.remove(2);
  ll.print_list();

  ll.remove(1);
  ll.remove(3);
  ll.remove(4);
  ll.print_list();

  return 0;
}