//
// Created by Chingfung Yung on 11/25/2018.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>

using namespace std;


template<typename T>
class queue
{
private:

    class Qnode
    {
    public:
        T element;
        Qnode *next;

        explicit Qnode(T e = 0) : element(e), next(nullptr)
        {}
    };

    Qnode *front;
    Qnode *rear;

public:

    queue() : front(nullptr), rear(nullptr)
    {}

    inline bool isEmpty() const
    { return front == nullptr; }

    void enqueue(T x);

    T dequeue();

    void makeEmpty();

    T getFront();

};


template <typename T>
T queue<T>::getFront()
{
    return front->element;
}

template<typename T>
void queue<T>::enqueue(const T x)
{
    if (isEmpty())
    {
        front = new Qnode(x);
        rear = front;
    }

    else
    {
        auto *p = new Qnode(x);

        rear->next = p;
        rear = rear->next;
    }
}

template<typename T>
T queue<T>::dequeue()
{
    T x;
    Qnode *p;
    if (!isEmpty())
    {
        x = front->element;

        p = front;
        front = front->next;

        delete p;

        return x;
    }
    else return ' ';
}

template<typename T>
void queue<T>::makeEmpty()
{
    while (!isEmpty())
        dequeue();
}

#endif //QUEUE_QUEUE_H
