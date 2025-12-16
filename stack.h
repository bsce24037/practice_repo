#ifndef STACK_H
#define STACK_H

#include"node.h"

template <typename T>

class LinkedStack
{
private:
    Node<T> *head;
    int size;

public:
    // Default Constructor:
    LinkedStack()
    {
        head = nullptr;
        size = 0;
    }
    // Destructor:
    ~LinkedStack()
    {
        Node<T> *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->getNext();
            delete temp;
        }
    }
    // memeber functions:
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
    // PRINT STACK:
    void printStack()
    {
        Node<T> *temp = head;

        while (temp != nullptr)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
    }

    void push(T data)
    {
        if (head == nullptr)
        {
            Node<T> *p = new Node<T>(data);
            head = p;
            size++;
        }
        else
        {

            Node<T> *p = new Node<T>(data);

            p->setNext(head);
            head = p;
            size++;
        }
    }

    T pop()
    {
        try
        {
            if (isEmpty() == true)
            {
                throw out_of_range("linked list is Empty");
            }
            else
            {
                Node<T> *po = head;

                T p = head->getData();
                head = head->getNext();

                delete po;

                if (size == 0)
                {
                    return T();
                }
                size--;
                return p;
            }
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
            return T();
        }
    }
    T seek()
    {
        try
        {
            if (isEmpty() == true)
            {
                throw out_of_range("linked list is Empty");
            }
            else
            {
                return head->getData();
            }
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
            return T();
        }
    }
    int getSize()
    {
        return size;
    }

    T search(T value)
    {
        Node<T>* temp = head;
        while(temp!=nullptr)
        {
            if(temp->data==value)
            {
                return temp;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        return nullptr;
    }
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
        size = 0;
    }
};

#endif