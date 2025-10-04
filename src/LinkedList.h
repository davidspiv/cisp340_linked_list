#pragma once

#include <iostream>
#include <string>

typedef std::string String;

struct Node {
  String name;
  Node* next = nullptr;
  Node* prev = nullptr;

  Node(const String& name) : name(name) {}
};

class LinkedList {
  Node* m_head;
  Node* m_tail;
  size_t m_size;

 public:
  LinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

  // ACCESSORS

  const Node* head() { return m_head; }
  const Node* tail() { return m_tail; }
  const size_t size() { return m_size; }

  // MODIFIERS

  void insertLast(const String& name) {
    Node* newNode = new Node(name);

    if (!m_tail) {
      // list is empty
      m_head = m_tail = newNode;
    } else {
      newNode->prev = m_tail;
      m_tail->next = newNode;
      m_tail = newNode;
    }
    ++m_size;
  }

  void insertAscending(const String& name) {
    Node* newNode = new Node(name);

    if (!m_tail) {
      // list is empty
      m_head = m_tail = newNode;
    } else {
      //   newNode->prev = m_tail;
      //   m_tail->next = newNode;
      //   m_tail = newNode;

      Node* curr = m_head;

      while (curr != m_tail || name > curr->next->name) {
        curr = curr->next;
      }

      curr->next = new Node(name);
    }
    ++m_size;
  }

  void print() {
    Node* curr = m_head;
    while (curr) {
      std::cout << curr->name << std::endl;
      curr = curr->next;
    }
  }

  void clear() {
    Node* curr;
    Node* prev;
    curr = prev = m_head;
    while (curr) {
      prev = curr;
      curr = curr->next;
      delete prev;
    }
  }
};
