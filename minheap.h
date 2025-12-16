#ifndef MINHEAP_H
#define MINHEAP_H

#include "Generic_files/queue/array.h"

template <typename T>
class MinHeap
{
private:
    MyArray<T> arr; // use your custom array

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i)
    {
        while (i > 0 && arr[parent(i)] > arr[i])
        {
            T temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < arr.get_size() && arr[l] < arr[smallest])
            smallest = l;
        if (r < arr.get_size() && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            T temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int cap = 10) : arr(cap) {}

    bool isEmpty() { return arr.get_size() == 0; }
    int size() { return arr.get_size(); }

    void insert(T val)
    {
        arr.append(val); // use append instead of push_back
        heapifyUp(arr.get_size() - 1);
    }

    T getMin()
    {
        if (isEmpty())
        {
            cout << "Heap empty\n";
            return T();
        }
        return arr[0];
    }
    T extractMin()
    {
        if (isEmpty())
        {
            cout << "Heap empty\n";
            return T();
        }
        T root = arr[0];
        int lastIndex = arr.get_size() - 1;
        arr[0] = arr[lastIndex];
        arr.removeAt(lastIndex);

        if (!isEmpty())
            heapifyDown(0);
        return root;
    }
    // Add these methods:
    bool contains(T val)
    {
        for (int i = 0; i < arr.get_size(); i++)
            if (arr[i] == val)
                return true;
        return false;
    }

    void decreaseKey(T oldVal, T newVal)
    {
        // Find index of oldVal
        int idx = -1;
        for (int i = 0; i < arr.get_size(); i++)
            if (arr[i] == oldVal)
            {
                idx = i;
                break;
            }

        if (idx == -1 || newVal > oldVal)
            return; // For min-heap

        arr[idx] = newVal;
        heapifyUp(idx);
    }
};

#endif