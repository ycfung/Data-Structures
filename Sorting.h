//
// Created by Chingfung Yung on 12/3/2018.
//

#ifndef DATA_STRUCTURES_SORTING_H
#define DATA_STRUCTURES_SORTING_H

#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
void SelectionSort(T arr[], int length)
{
    int i, j, min_idx;


    for (i = 0; i < length - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < length; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

template<typename T>
void QuickSort(T *arr, int left, int right)
{

    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */

    while (i <= j)
    {

        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /*recursion*/

    if (left < j)
        QuickSort(arr, left, j);

    if (i < right)
        QuickSort(arr, i, right);

}


#endif //DATA_STRUCTURES_SORTING_H
