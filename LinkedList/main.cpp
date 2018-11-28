#include <iostream>
#include <ctime>
#include <random>
#include "List.h"
#include "ListNode.h"

using namespace std;


int main()
{


    const int size = 10;
    int arr[size];
    random_device rd;
    default_random_engine gen = std::default_random_engine(rd());
    uniform_int_distribution<int> dis(1, 100); //from C++11 random library
    for (int i = 0; i <= size - 1; i++)
    {
        arr[i] = dis(gen); //assigns random number in array
    }
    //random list if needed

    List<int> intList; //creates order linked list
    for (int i = 0; i <= size - 1; ++i)
    {
        intList.insertNewNode(i); //inserts value from array to the linked list in the proper positions
    }



    intList.print();
    intList.insertEnd(233);
    intList.insertBegin(666);
    intList.print();
    intList.search(3);
    intList.insertCurrent(999);
    intList.print();
    intList.deleteCurrent();
    intList.deleteBegin();
    intList.print();
    intList.deleteEnd();
    intList.print();
    return 0;
}
