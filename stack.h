#include <iostream>
#include <string>
#include "SLinkedList.h"
using namespace std;
template <typename T>
class Stack {
private:
    SLinkedList<T> list;
public:
    Stack()
    {
    }

    void push(T value) {
        list.prepend(value);
    }

    T pop() {
        if (list.isEmpty()) {
            cout << "Stack empty";
            return T();
        }
        T value = list.getHead()->data;
        list.deleteFromStart();
        return value;
    }

    T top() {
        if (list.isEmpty()) {
            cout << "Stack empty\n";
            return T();
        }
        return list.getHead()->data;
    }

    bool isEmpty() {
        return list.isEmpty();
    }
};
