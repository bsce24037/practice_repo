#ifndef CIRCULAR_LLIST_H
#define CIRCULAR_LLIST_H

#include "Generic_files/stack/node.h"
#include <iostream>
using namespace std;

template <typename T>
class CircularLinkedList
{
private:
    Node<T> *head;
    int size;

public:
    CircularLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    ~CircularLinkedList()
    {
        clear();
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    // ---------------------------
    // Insert at Head - FIXED
    // ---------------------------
    void insertAtHead(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->setNext(head); // ✅ Use setter
        }
        else
        {
            Node<T> *temp = head;

            // last node find karo
            while (temp->getNext() != head)
                temp = temp->getNext();

            newNode->setNext(head); // ✅ Use setter
            temp->setNext(newNode); // ✅ Use setter
            head = newNode;
        }
        size++;
    }

    // ---------------------------
    // Insert at Tail - FIXED
    // ---------------------------
    void insertAtTail(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->setNext(head); // ✅ Use setter
        }
        else
        {
            Node<T> *temp = head;

            while (temp->getNext() != head)
                temp = temp->getNext();

            temp->setNext(newNode); // ✅ Use setter
            newNode->setNext(head); // ✅ Use setter
        }
        size++;
    }

    // ---------------------------
    // Search a value - FIXED
    // ---------------------------
    Node<T> *search(T value) const
    {
        if (head == nullptr)
            return nullptr;

        Node<T> *temp = head;

        do
        {
            if (temp->getData() == value)
                return temp;

            temp = temp->getNext();
        } while (temp != head);

        return nullptr;
    }

    // ---------------------------
    // Delete a value - FIXED
    // ---------------------------
    bool deleteValue(T value)
    {
        if (head == nullptr)
            return false;

        Node<T> *curr = head;
        Node<T> *prev = nullptr;

        // If value is in head
        if (head->getData() == value)
        {
            // Only one node in list
            if (head->getNext() == head)
            {
                delete head;
                head = nullptr;
                size--;
                return true;
            }

            // Find last node
            Node<T> *last = head;
            while (last->getNext() != head)
                last = last->getNext();

            last->setNext(head->getNext()); // ✅ Use setter

            Node<T> *del = head;
            head = head->getNext();

            delete del;
            size--;
            return true;
        }

        // If value somewhere else
        prev = head;
        curr = head->getNext();

        while (curr != head)
        {
            if (curr->getData() == value) 
            {
                prev->setNext(curr->getNext());
                delete curr;
                size--;
                return true;
            }
            prev = curr;
            curr = curr->getNext();
        }

        return false;
    }

    // ---------------------------
    // Print List
    // ---------------------------
    void printList() const
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node<T> *temp = head;

        do
        {
            cout << temp->getData() << " -> ";
            temp = temp->getNext();
        } while (temp != head);

        cout << "(HEAD)\n";
    }

    void clear()
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;

        do
        {
            Node<T> *nextNode = temp->getNext();
            delete temp;
            temp = nextNode;
        } while (temp != head);

        head = nullptr;
        size = 0;
    }

    int getSize() const
    {
        return size;
    }

    // Helper function to get head
    Node<T> *getHead() const
    {
        return head;
    }
};

#endif