//
// Created by Chingfung Yung on 11/25/2018.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>

using namespace std;
template<typename T>
class Stack
{
public:
    explicit Stack(int size);

    ~Stack();

    bool isEmpty();

    bool isFull();

    void clear();

    bool push(T elem);

    bool pop(T &elem);

    bool peek(T &elem);


private:
    T *m_pStack;
    int m_iSize;
    int m_iTop;
};


template<typename T>
Stack<T>::Stack(int size)
{
    m_iSize = size;
    m_pStack = new T[m_iSize];
    m_iTop = 0;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] m_pStack;
    m_pStack = nullptr;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return m_iTop == 0;
}

template<typename T>
bool Stack<T>::isFull()
{
    return m_iTop == m_iSize;
}

template<typename T>
void Stack<T>::clear()
{
    m_iTop = 0;
}

template<typename T>
bool Stack<T>::push(T elem)
{
    if (isFull())
    {
        cout << "stackoverflow" << endl;
        return false;
    }
    else
    {
        m_pStack[m_iTop++] = elem;
        return true;
    }
}

template<typename T>
bool Stack<T>::pop(T &elem)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        elem = m_pStack[--m_iTop];
        cout << elem << ' ';
        return true;
    }
}

template<typename T>
bool Stack<T>::peek(T &elem)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        elem = m_pStack[m_iTop - 1];
        cout << elem << ' ';
        return true;
    }
}


#endif //STACK_STACK_H
