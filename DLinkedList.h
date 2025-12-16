#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class DNode {
public:
    T data;
    DNode<T>* next;
    DNode<T>* prev;
    DNode(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
template <typename T>
class DLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
    int count;
public:
    DLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~DLinkedList() {
        DNode<T>* temp = head;
        while (temp != nullptr) {
            DNode<T>* nextN = temp->next;
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
        DNode<T>* newN = new DNode<T>(value);
        if (isEmpty()) {
            head = newN;
            tail = newN;
        }
        else {
            tail->next = newN;
            newN->prev = tail;
            tail = newN;
        }
        count++;
    }
    void prepend(T value) {
        DNode<T>* newN = new DNode<T>(value);
        if (isEmpty()) {
            head = newN;
            tail = newN;
        }
        else {
            newN->next = head;
            head->prev = newN;
            head = newN;
        }
        count++;
    }
    void insertAtIndex(T value, int index) {
        if (index >= 0 && index <= count) {
            if (isEmpty()) {
                DNode<T>* newN = new DNode<T>(value);
                head = newN;
                tail = newN;
                count++;
            }
            else if (index == 0) {
                prepend(value);
            }
            else if (index == count) {
                append(value);
            }
            else {
                // for middle index beside 1 and last
                DNode<T>* newN = new DNode<T>(value);
                DNode<T>* old = head;
                for (int i = 0;i < index - 1;i++) {
                    old = old->next;
                }
                DNode<T>* nextN = old->next;
                newN->next = nextN;
                newN->prev = old;
                nextN->prev = newN;
                old->next = newN;
                count++;
            }
        }
        else {
            cout << "index is wrong" << endl;
            return;
        }
    }
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return;
        }
        // for one node
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            DNode<T>* delN = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete delN;
        }
        count--;
    }
    void deleteFromStart() {
        if (isEmpty()) {
            cout << "empty" << endl;
            return;
        }
        // for one node
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            DNode<T>* delN = head;
            head = head->next;
            head->prev = nullptr;
            delete delN;
        }
        count--;
    }
    void deleteFromIndex(int index) {
        if (index >= 0 && index < count) {
            if (isEmpty()) {
                cout << "empty" << endl;
                return;
            }// for one node
            else if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else if (index == 0) {
                deleteFromStart();
            }
            else if (index == count - 1) {
                deleteFromEnd();
            }
            else {// for middle indexes
                DNode<T>* delN = head;
                for (int i = 0;i < index;i++) {
                    delN = delN->next;
                }
                DNode<T>* prevofdelN = delN->prev;
                DNode<T>* nextofdelN = delN->next;
                prevofdelN->next = nextofdelN;
                nextofdelN->prev = prevofdelN;
                delete delN;
                count--;
            }
        }
        else {
            cout << "index is wrong" << endl;
            return;
        }
    }
    DNode<T>* getHead() {
        return head;
    }
    DNode<T>* getTail() {
        return tail;
    }
    void printList() {
        DNode<T>* show = head;
        while (show != nullptr) {
            cout << show->data;
            cout << " ";
            show = show->next;
        }
    }
};
#endif

