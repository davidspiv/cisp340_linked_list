#pragma once

#include <sstream>
#include <string>

typedef std::string String;

class Node {
    String m_name;
    Node* m_next = nullptr;
    Node* m_prev = nullptr;

public:
    // ACCESSORS
    String name() const { return m_name; }
    Node* next() const { return m_next; }
    Node* prev() const { return m_prev; }

    // MODIFIERS
    void setName(String const& name) { m_name = name; }
    void setNext(Node* next) { m_next = next; }
    void setPrev(Node* prev) { m_prev = prev; }

    Node(String const& name)
        : m_name(name)
    {
    }
};

class LinkedList {
    Node* m_head;
    Node* m_tail;
    size_t m_size;

public:
    LinkedList()
        : m_head(nullptr)
        , m_tail(nullptr)
        , m_size(0)
    {
    }

    ~LinkedList() { clear(); }

    // ACCESSORS

    Node const* head() const { return m_head; }
    Node const* tail() const { return m_tail; }
    size_t size() const { return m_size; }

    // MODIFIERS

private:
    void insertOnly(String const& name) { m_head = m_tail = new Node(name); }

    // pre-condition: non-empty list
    void insertLast(String const& name)
    {
        Node* newNode = new Node(name);
        newNode->setPrev(m_tail);
        m_tail->setNext(newNode);
        m_tail = newNode;
    }

    // pre-condition: non-empty list
    void insertFirst(String const& name)
    {
        Node* newNode = new Node(name);
        newNode->setNext(m_head);
        m_head->setPrev(newNode);
        m_head = newNode;
    }

    // pre-condition: non-empty list
    void insertWithin(String const& name, Node* curr)
    {
        Node* newNode = new Node(name);
        newNode->setPrev(curr);
        newNode->setNext(curr->next());

        curr->setNext(newNode);
        newNode->next()->setPrev(newNode);
    }

public:
    // adds name to list in ascending order
    void insert(String const& name)
    {
        if (!m_tail) {
            insertOnly(name);

        } else if (name < m_head->name()) {
            insertFirst(name);

        } else {
            Node* curr = m_head;

            while (curr != m_tail && !(name < curr->next()->name())) {
                curr = curr->next();
            }

            if (curr == m_tail) {
                insertLast(name);

            } else { // middle
                insertWithin(name, curr);
            }
        }

        ++m_size;
    }

    void clear()
    {
        Node* curr;
        Node* prev;
        curr = prev = m_head;
        while (curr) {
            prev = curr;
            curr = curr->next();
            delete prev;
        }

        m_head = m_tail = nullptr;
        m_size = 0;
    }

    // UTIL

    String ascendingAsString() const
    {
        Node const* curr = m_head;
        std::stringstream names;

        while (curr) { // forwards
            names << curr->name() << std::endl;
            curr = curr->next();
        }

        return names.str();
    }

    String descendingAsString() const
    {
        Node const* curr = m_tail;
        std::stringstream names;

        while (curr) { // backwards
            names << curr->name() << std::endl;
            curr = curr->prev();
        }

        return names.str();
    }
};
