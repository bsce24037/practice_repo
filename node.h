#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>

class Node
{
private:
    T data;
    Node<T> *next;

public:
    // Parametarized Constructor:
    // template<typename T>
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
    // Destructor:
    ~Node()
    {
        next = nullptr;
    }

    // getter and setter:
    void setNext(Node<T> *val)
    {
        this->next = val;
    }
    Node<T> *getNext()
    {
        return next;
    }
    void setData(T data)
    {
        this->data = data;
    }
    T getData()
    {
        return data;
    }
};

#endif