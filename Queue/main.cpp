
#include "Queue.h"

int main()
{
    queue<char> temp;
    temp.enqueue('a');
    temp.enqueue('b');
    temp.enqueue('c');
    cout<<temp.dequeue()<<' ';
    cout<<temp.dequeue()<<' ';
    cout<<temp.getFront()<<' ';
    cout<<temp.dequeue()<<' ';
    return 0;
}