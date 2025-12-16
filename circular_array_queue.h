#ifndef CIRCULARARRAYQUEUE_H
#define CIRCULARARRAYQUEUE_H

#include<iostream>
using namespace std;

template<typename T>

class CircularQueue
{
private:
    T *array;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Default constructor:

    CircularQueue()
    {
        capacity = 10;
        front = 0;
        rear = -1;
        size = 0;
        array = new T[capacity];
    }

    // Destructor:
    ~CircularQueue()
    {
        delete[] array;
        front = 0;
        rear = -1;
        size = 0;
        capacity = 10;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            // cout << "\n ...CircularQueue is Empty..." << "\n";
            return true;
        }
        // cout << "\n CircularQueue is not Emmpty:" << endl;
        return false;
    }

    bool isFull()
    {
        if (size == capacity)
        {
            return true;
        }
        return false;
    }
    
    void resize()
    {
        int newcap = capacity * 2;
        T *temp = new T[newcap];
        for (auto i = 0; i < size;i++)
        {
            temp[i] = array[(front + i) % capacity];
        }

        delete[] array;
        array = temp;
        capacity = newcap;
        front = 0;
        rear = size - 1;
    }
    // function to add element in the last of the array:
    void enqueue(T data)
    {
        if (isFull() == true)
        {
            resize();
        }
        rear = (rear + 1) % capacity;
        array[rear] = data;
        size++;
    }

    // dequeue an element from the front of the array:

    T dequeue()
    {
        try
        {
            if (isEmpty() == true)
            {
                throw underflow_error("your CircularQueue is Empty first add some thing:");
            }
            else
            {

                T val;
                val = array[front];
                front = (front + 1) % capacity;
                size = size - 1;
                return val;
            }
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
            return T();
        }
    }

    // take the top element of the array:

    T peek()
    {
        try
        {
            if (isEmpty() == true)
            {
                throw underflow_error("your CircularQueue is Empty first add some thing:");
            }
            else
            {
                T val;
                val = array[front];

                return val;
            }
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
            return T();
        }
    }
    void clear()
    {

        delete[] array;
        capacity = 10;
        array = new T[capacity];

        size = 0;
        front = 0;
        rear = -1;
    }

    void printQueue()
    {

        try
        {
            if (isEmpty())
            {
                throw underflow_error("your CircularQueue is Empty first add some thing:");
            }
            else
            {
                for (auto i =0; i < size; i++)
                {
                    cout << array[(front+i)%capacity] << " ";
                }
                cout << "\n";
            }
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }

    int search(T key) 
    {
        if (isEmpty()==true)
            return -1;

        for (int i = 0; i < size; i++)
        {
            int index = (front + i) % capacity;
            if (array[index] == key)
                return index;
        }
        return -1; // Not found
    }
};

#endif