//
// Created by Chingfung Yung on 12/3/2018.
// This file includes two sorting algorithms, demos and a random funcion
//
#ifndef DATA_STRUCTURES_SORTING_H
#define DATA_STRUCTURES_SORTING_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>

using namespace std;


template<typename T>
int QuickSort(vector<T> &target, int left, int right, int &count)
{
    if (left >= right) return 0;
    int i = left, j = right;
    int tmp, pivot = target[i];

    while (true)
    {
        while (target[i] < pivot)
            i++;
        while (pivot < target[j])
            j--;

        if (i >= j)
            break;

        count++;
        tmp = target[i];
        target[i] = target[j];
        target[j] = tmp;
        i++;
        j--;
    }

    QuickSort(target, left, i - 1, count);
    QuickSort(target, j + 1, right, count);

    return count;
}


int randint(int lower, int upper)
{
    random_device rd;
    auto gen = std::mt19937(rd());
    uniform_int_distribution<int> dis(lower, upper);
    return dis(gen);
}


void QuickSort_demo(int length, int n)
{
    double times = 0;

    ofstream outfile;
    outfile.open("output_quick_sort.txt", ios::app);

    vector<int> vec;
    for (int j = 0; j < n; j++)
    {


        vec.clear();

        for (int i = 0; i <= length; i++)
            vec.push_back(randint(10, 1000000));


        for (auto ptr:vec)
            outfile << ptr << ' ';
        outfile << endl;

        int count = 0;

        int time = QuickSort(vec, 0, int(vec.size() - 1), count);

        times += time;

        for (auto ptr:vec)
            outfile << ptr << ' ';
        outfile << endl;

        outfile << time << endl;

    }

    times = times / n;
    outfile << endl << endl << "Average compare times: " << times;
}



template<typename T>
int SelectionSort(vector<T> &vec, int length)
{
    int i, j, min_idx, count = 0;

    for (i = 0; i < length - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < length; j++)
            if (vec[j] < vec[min_idx])
            {
                min_idx = j;
                count++;
            }
        swap(vec[min_idx], vec[i]);
    }
    return count;
}

 void SelectionSort_demo(int length)
{
    vector<int> vec;

    for (int i = 0; i <= length; i++)
        vec.push_back(randint(10, 1000000));

    ofstream outfile;
    outfile.open("output_selection_sort.txt", ios::app);
    for (auto ptr:vec)
        outfile << ptr << ' ';
    outfile << endl;

    int times = SelectionSort(vec, int(vec.size()));

    for (auto ptr:vec)
        outfile << ptr << ' ';
    outfile << endl;

    outfile << times << endl;

}


#endif //DATA_STRUCTURES_SORTING_H
