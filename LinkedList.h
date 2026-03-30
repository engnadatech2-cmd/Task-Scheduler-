#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    // Copy Constructor
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node<T>* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    // Assignment operator
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    T front() const {
        if (!head) throw std::out_of_range("Queue is empty");
        return head->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            pop_front();
        }
    }
};

#endif // LINKEDLIST_H
