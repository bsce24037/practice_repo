#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>
#include<iostream>
using namespace std;

template <typename T>
class Sort
{
public:
    // Radix Sort with key extractor
    void sort(T arr[], int n, int (T::*getKey)() const)
    {
        if (n <= 1)
            return;

        int maxKey = (arr[0].*getKey)();
        for (int i = 1; i < n; i++)
        {
            int key = (arr[i].*getKey)();
            if (key > maxKey)
                maxKey = key;
        }

        for (int exp = 1; maxKey / exp > 0; exp *= 10)
        {
            countSort(arr, n, exp, getKey);
        }
    }

private:
    void countSort(T arr[], int n, int exp, int (T::*getKey)() const)
    {
        vector<T> output(n);
        int count[10] = {0};

        for (int i = 0; i < n; i++)
        {
            int digit = ((arr[i].*getKey)() / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            int digit = ((arr[i].*getKey)() / exp) % 10;
            output[--count[digit]] = arr[i];
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
};

#endif
