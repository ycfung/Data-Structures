#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "myio.h"
#include <iostream>
#include "ListNode.h"
using namespace std;

template<typename T>
class List //linked list of ListNode objects
{
public:
    List();

    ~List();

    bool deleteCurrent();

    bool deleteBegin();

    bool deleteEnd();

    void insertNewNode(T);

    void insertCurrent(T);

    void insertBegin(T);

    void insertEnd(T);

    void print();

    ListNode<T> *search(T);

    bool isEmpty();

private:
    ListNode<T> *currentPtr;

    ListNode<T> *startPtr;

    ListNode<T> *endPtr;
};


template<typename T>
bool List<T>::deleteEnd()
{
    if (endPtr != nullptr)
    {
        ListNode<T> *ptr = startPtr;
        while (ptr->nextPtr != endPtr)
            ptr = ptr->nextPtr;
        delete (endPtr);
        endPtr = ptr;
        endPtr->nextPtr = nullptr;
        return true;
    }
    else return false;
}


template<typename T>
bool List<T>::deleteBegin()
{
    if (startPtr != nullptr)
    {
        ListNode<T> *ptr = startPtr;
        startPtr = startPtr->nextPtr;
        delete (ptr);
        return true;
    }
    else return false;
}


template<typename T>
bool List<T>::deleteCurrent() //pos is the position of the data to delete, starts from zero
{
    if (currentPtr != nullptr)
    {
        ListNode<T> *ptr = startPtr;
        while (ptr->nextPtr != currentPtr)
            ptr = ptr->nextPtr;
        ptr->nextPtr = currentPtr->nextPtr;
        delete (currentPtr);
        currentPtr = ptr;
        return true;
    }
    else
        return false;

}


template<typename T>
List<T>::List() //creates list with start and end as NULL
{
    startPtr = nullptr;
    endPtr = nullptr;
    currentPtr = nullptr;
}

template<typename T>
List<T>::~List()
{
    if (!isEmpty()) // List is not empty
    {
        ListNode<T> *currentPtr = startPtr;
        ListNode<T> *tempPtr;

        while (currentPtr != 0) // delete remaining nodes
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }
}

template<typename T>
bool List<T>::isEmpty()
{
    return startPtr == nullptr && endPtr == nullptr;
}

template<typename T>
void List<T>::insertBegin(T dataIn)
{
    if (isEmpty()) //if the list is empty create first element of the list
    {
        auto *newPtr = new ListNode<T>(dataIn); //creates new node
        startPtr = newPtr; //start and end pointer are same becuase there is only one object in list
        endPtr = newPtr;
    }
    else //if node(s) exist in list insert additional object before the first
    {
        auto *newPtr = new ListNode<T>(dataIn);
        newPtr->nextPtr = startPtr; //the next pointer of the new node points to the node that was previously first
        startPtr = newPtr; //the pointer for the new node is now the starting node
    }
}

template<typename T>
void List<T>::insertEnd(T dataIn)
{
    if (isEmpty()) //if the list is empty create first element of the list
    {
        auto *newPtr = new ListNode<T>(dataIn);
        startPtr = newPtr;
        endPtr = newPtr;
    }
    else //if node(s) exist in the list then insert new node at the end of the list
    {
        auto *newPtr = new ListNode<T>(dataIn);
        endPtr->nextPtr = newPtr; //the current last node's next pointer points to the new node
        endPtr = newPtr; //the new node is now the last node in the list
    }
}

template<typename T>
void List<T>::insertNewNode(T dataIn) //NOLINT
{
    if (isEmpty())
    {
        insertBegin(dataIn);
        currentPtr = startPtr;
    }
    else
    {
        insertEnd(dataIn);
        currentPtr = endPtr;
    }//Denote if you need the list to be sorted
    /*
    else
    {
        if (dataIn <
            startPtr->data) //if the data of the new object is less than than the data of first node in list insert at beginning
        {
            insertBegin(dataIn);
        }
        else if (dataIn >=
                 endPtr->data) //if the data of the new object is greater than than the data of last node in list insert at end
        {
            insertEnd(dataIn);
        }

        else //the new node is being inserted in order but not at the beginning or end
        {
            auto currentPtr = startPtr;
            auto *newPtr = new ListNode<T>(dataIn);
            while (currentPtr != endPtr) //runs to the end of the list
            {
                //if the data of the new node is less the data in the next node and greater than the data in the current node, insert after current node
                if ((newPtr->data < currentPtr->nextPtr->data) && (newPtr->data >= currentPtr->data))
                {
                    auto next = currentPtr->nextPtr;
                    currentPtr->nextPtr = newPtr;
                    newPtr->nextPtr = next;
                    break;
                }
                currentPtr = currentPtr->nextPtr; //moves to the next node in the list
            }
        }

    }
    */
}

template<typename T>
void List<T>::print()
{
    if (isEmpty())
    {
        cout << "The list is empty" << endl;

    }
    else
    {
        ListNode<T> *currentPtr = startPtr;

        cout << "The contents of the list is: ";
        while (currentPtr != nullptr) //prints until the end of the list is reached
        {
            cout << currentPtr->data;
            if (currentPtr->nextPtr != nullptr)
                cout << " -> ";
            currentPtr = currentPtr->nextPtr; //moves to next node in list
        }
        cout << endl;
    }
}

template<typename T>
ListNode<T> *List<T>::search(T key) //search functions that searches for node that contains data equal to the key
{
    ListNode<T> *nodePtr;
    bool found = false;
    int pos = 0;
    nodePtr = startPtr;

    while ((!found) && (nodePtr != nullptr))
    {
        if (nodePtr->data == key)
            found = true;
        else
        {
            pos++;
            nodePtr = nodePtr->nextPtr;
        }
    }
    currentPtr = nodePtr;
    if (found)
        cout << "Current pointer is at " << pos << ", the value " << key << " is found." << endl;
    else
        cout << "Not found." << endl;
    return nodePtr;
}


template<typename T>
void List<T>::insertCurrent(T dataIn)
{
    auto *newPtr = new ListNode<T>(dataIn);
    newPtr->nextPtr = currentPtr->nextPtr;
    currentPtr->nextPtr = newPtr;
}

#endif //TEST_LIST_H
