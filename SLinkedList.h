#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T value) {
        data = value;
        next = nullptr;
    }
};
template <typename T>
class SLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
    SLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~SLinkedList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* nextN = temp->next;
            delete temp;
            temp = nextN;
        }
    }
    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    void append(T value) {
        Node<T>* newN = new Node<T>(value);
        if (isEmpty()) {
            head = newN;
            tail = newN;
        }
        else {
            tail->next = newN;
            tail = newN;
        }
        count++;
    }
    void prepend(T value) {
        Node<T>* newN = new Node<T>(value);
        if (isEmpty()) {
            head = newN;
            tail = newN;
        }
        else {
            newN->next = head;
            head = newN;
        }
        count++;
    }
    void insertAt(T value, int index) {
        if (index >= 0 && index <= count) {

            if (index == 0) {
                prepend(value);
            }
            else if (index == count) {
                append(value);
            }
            else {
                Node<T>* newN = new Node<T>(value);
                Node<T>* old = head;
                for (int i = 0;i < index - 1;i++) {
                    old = old->next;
                }
                newN->next = old->next;
                old->next = newN;
                count++;
            }
        }
        else {
            cout << "invalid index" << endl;
        }
    }
    void deleteFromLast() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp->next = nullptr;
        }
        count--;
    }
    void deleteFromStart() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        count--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    void deleteAt(int index) {
        if (index >= 0 && index < count) {
            if (index == 0) {
                deleteFromStart();
            }
            else if (index == count - 1) {
                deleteFromLast();
            }
            else {
                Node<T>* old = head;
                for (int i = 0;i < index - 1;i++) {
                    old = old->next;
                }
                Node<T>* tempDel = old->next;
                old->next = tempDel->next;
                delete tempDel;
                count--;
            }
        }
        else {
            cout << "invalid index" << endl;
        }
    }
    Node<T>* getHead() {
        return head;
    }
    Node<T>* getTail() {
        return tail;
    }
    void print() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
#endif

