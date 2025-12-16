// MyArray.h
#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class MyArray
{
private:
    T *data;
    int size;
    int capacity;

public:
    // ========== CONSTRUCTORS ==========
    MyArray()
    {
        size = 0;
        capacity = 5;
        data = new T[capacity];
        cout << "MyArray created (default cap: " << capacity << ")\n";
    }

    MyArray(int cap)
    {
        if (cap <= 0)
            cap = 5;
        size = 0;
        capacity = cap;
        data = new T[capacity];
        cout << "MyArray created (cap: " << capacity << ")\n";
    }

    // ========== COPY CONSTRUCTOR ==========
    MyArray(const MyArray &other)
    {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
        cout << "MyArray copied\n";
    }

    // ========== DESTRUCTOR ==========
    ~MyArray()
    {
        delete[] data;
        cout << "MyArray destroyed\n";
    }

    // ========== OPERATOR= ==========
    MyArray &operator=(const MyArray &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // ========== APPEND ==========
    void append(T obj)
    {
        // Check if resize needed
        if (size >= capacity)
        {
            int newCapacity = capacity * 2;
            T *newData = new T[newCapacity];

            // Copy old data
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }

            // Cleanup old
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        // Add new element
        data[size] = obj;
        size++;
    }

    // ========== PREPEND ==========
    void prepend(T obj)
    {
        // First ensure capacity
        if (size >= capacity)
        {
            int newCapacity = capacity * 2;
            T *newData = new T[newCapacity];

            // Start with new element
            newData[0] = obj;

            // Copy old data (shifted by 1)
            for (int i = 0; i < size; i++)
            {
                newData[i + 1] = data[i];
            }

            delete[] data;
            data = newData;
            capacity = newCapacity;
            size++;
        }
        else
        {
            // Shift elements right
            for (int i = size; i > 0; i--)
            {
                data[i] = data[i - 1];
            }
            data[0] = obj;
            size++;
        }
    }

    // ========== GETTERS ==========
    int get_size() const
    {
        return size;
    }

    int get_capacity() const
    {
        return capacity;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    // ========== ACCESS OPERATORS ==========
    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            cerr << "MyArray: Index out of bounds!" << endl;
            static T dummy;
            return dummy;
        }
        return data[index];
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            cerr << "MyArray: Index out of bounds!" << endl;
            static T dummy;
            return dummy;
        }
        return data[index];
    }

    // ========== FIND ==========
    int find(const T &obj) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == obj)
            {
                return i;
            }
        }
        return -1;
    }

    // ========== INSERT AT ==========
    void insertAt(int index, T obj)
    {
        if (index < 0 || index > size)
        {
            cout << "Invalid index for insert\n";
            return;
        }

        if (index == 0)
        {
            prepend(obj);
            return;
        }

        if (index == size)
        {
            append(obj);
            return;
        }

        // Check capacity
        if (size >= capacity)
        {
            int newCapacity = capacity * 2;
            T *newData = new T[newCapacity];

            // Copy up to index
            for (int i = 0; i < index; i++)
            {
                newData[i] = data[i];
            }

            // Insert new element
            newData[index] = obj;

            // Copy rest
            for (int i = index; i < size; i++)
            {
                newData[i + 1] = data[i];
            }

            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        else
        {
            // Shift elements right
            for (int i = size; i > index; i--)
            {
                data[i] = data[i - 1];
            }
            data[index] = obj;
        }
        size++;
    }

    // ========== REMOVE AT ==========
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index for remove\n";
            return;
        }

        // Shift elements left
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    // ========== DISPLAY ==========
    void display() const
    {
        if (size == 0)
        {
            cout << "Array is empty\n";
            return;
        }

        cout << "MyArray (size=" << size << ", cap=" << capacity << "): ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << endl;
    }

    // ========== CLEAR ==========
    void clear()
    {
        size = 0;
    }

    // ========== UPDATE ==========
    void update(int index, T obj)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index for update\n";
            return;
        }
        data[index] = obj;
    }
};

#endif // MYARRAY_H