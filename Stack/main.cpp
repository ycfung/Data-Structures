#include <iostream>
#include "stack.h"
int main()
{
    char temp;
    Stack<char> stack(10);
    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.pop(temp);
    stack.pop(temp);
    stack.pop(temp);
    stack.push('e');
    stack.pop(temp);
    stack.peek(temp);
    stack.pop(temp);
    return 0;
}
