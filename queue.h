#include <iostream>
#include <string>
#include "SLinkedList.h"
using namespace std;
template<typename T>
class Queue {
private:
    SLinkedList<T> list;

public:
    Queue() {}

    void enqueue(T value) {
        list.append(value);
    }

    T dequeue() {
        if (list.isEmpty()) {
            cout << "Queue empty\n";
            return T();
        }
        T value = list.getHead()->data;
        list.deleteFromStart();
        return value;
    }

    T front() {
        if (list.isEmpty()) {
            cout << "Queue empty\n";
            return T();
        }
        return list.getHead()->data;
    }

    bool isEmpty() {
        return list.isEmpty();
    }
};


template <typename T>
class CircularQueue {
private:
    T* array;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int cap = 10) {
        capacity = cap;
        array = new T[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    ~CircularQueue() {
        delete[] array;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(T value) {
        // Inline resizing if full
        if (isFull()) {
            int newCapacity = capacity * 2;
            T* newArr = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = array[(front + i) % capacity];
            }
            delete[] array;
            array = newArr;
            capacity = newCapacity;
            front = 0;
            rear = size;
        }

        array[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return T();
        }
        T value = array[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    T getFront() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return T();
        }
        return array[front];
    }

    int getSize() {
        return size;
    }

    void clear() {
        front = 0;
        rear = 0;
        size = 0;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};