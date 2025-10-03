#include <fstream>
#include <iostream>

struct Node {
  int value;
  Node *next = NULL;

  Node(int value = 0) : value(value) {}
};

struct LinkedList {
  Node *head = new Node;

  void insertIncrementally(int value) {
    Node *curr;
    Node *prev;
    curr = prev = head;

    // while (curr) {
    //   curr->next = prev;
    //   prev = curr;
    //   curr = curr->next;
    // }
  }

  void clear() {
    Node *curr;
    Node *prev;
    curr = prev = head;
    while (curr) {
      prev = curr;
      curr = curr->next;
      delete prev;
    }
  }

  // returns head if lest is only one element long
  void getPenultimateIndex() {
    Node *curr = head;
    while (head && curr->next && curr->next->next) {
      curr = curr->next;
    }

    std::cout << curr->value << std::endl;
  }

  void getMiddleIndex() {
    Node *fast;
    Node *slow;
    fast = slow = head;
    while (head && fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    std::cout << slow->value << std::endl;
  }


  void addNode(int value = 0) {
    Node *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new Node(value);
  }

  void traverse() { // pass head

    Node *curr = head;
    while (curr) {
      std::cout << curr->value << std::endl;
      curr = curr->next;
    }
  }

  void traverse(Node **curr) { // pass current address of head
    while (*curr) {
      std::cout << (*curr)->value << std::endl;
      curr = &(*curr)->next;
    }
  }
};

int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.addNode(4);
  list.addNode(5);
  list.addNode(6);
  list.insertIncrementally(3);
  list.traverse();
  // list.getPenultimateIndex();
}
