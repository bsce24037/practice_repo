#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template <typename T>
class LinkedQueue
{
private:
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    LinkedQueue()
    {
        front = rear = nullptr;
        size = 0;
    }

    ~LinkedQueue()
    {
        clear();
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(const T &data)
    {
        Node<T> *p = new Node<T>(data);

        if (isEmpty())
        {
            front = rear = p;
        }
        else
        {
            rear->setNext(p);
            rear = p;
        }
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
            return front->getData(); 
        }

        Node<T> *temp = front;
        T value = front->getData();

        front = front->getNext();
        delete temp;
        size--;

        if (front == nullptr)
            rear = nullptr;

        return value;
    }

    T peek() const
    {
        if (isEmpty())
        {
            cout << "Queue empty!" << endl;
            return front->getData(); 
        }
        return front->getData();
    }

    int getSize() const
    {
        return size;
    }

    void printQueue() const
    {
        Node<T> *temp = front;
        while (temp != nullptr)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

#endif
