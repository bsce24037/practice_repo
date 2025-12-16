#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class DArray {
private:
    T* data;
    int size;
    int capacity;
public:
    DArray() {
        capacity = 10;
        data = new T[capacity];
        size = 0;
    }
    DArray(int cap) {
        capacity = cap;
        data = new T[capacity];
        size = 0;
    }
    ~DArray() {
        delete[] data;
    }
    void resize(int cap) {
        T* newD = new T[cap];
        for (int i = 0;i < size;i++) {
            newD[i] = data[i];
        }
        delete[] data;
        data = newD;
        capacity = cap;
    }
    void append(T value) {
        if (size == capacity) {
            int newC = capacity * 2;
            resize(newC);
        }
        data[size] = value;
        size++;
    }
    void deleteFromLast() {
        if (size > 0) {
            size--;
        }
        else {
            cout << "already empty" << endl;
        }
    }
    void insertAt(T value, int index) {
        if (index >= 0 && index <= size) {
            if (size == capacity) {
                int newC = capacity * 2;
                resize(newC);
            }
            for (int i = size;i > index;i--) {
                data[i] = data[i - 1];
            }
            data[index] = value;
            size++;
        }
        else {
            cout << "invalid index" << endl;
        }
    }
    void deleteAt(int index) {
        if (index >= 0 && index < size) {
            for (int i = index;i < size - 1;i++) {
                data[i] = data[i + 1];
            }
            size--;
        }
        else {
            cout << "invalid index" << endl;
        }
    }
    T& operator[] (int index)const {
        if (index < 0 || index >= size) {
            cout << "throw error" << endl;
        }
        return data[index];
    }

    int length() {
        return size;
    }
    void print() {
        for (int i = 0;i < size;i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    //sorting algorithms
    void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    void selectionSort() {
        for (int i = 0;i < size - 1;i++) {
            int min_index = i;
            for (int j = i + 1;j < size;j++) {
                if (data[j] < data[min_index])
                    min_index = j;
            }
            T temp = data[i];
            data[i] = data[min_index];
            data[min_index] = temp;
        }
    }
};
#endif
