#include <iostream>
#include <string>

using namespace std;


char input_char()
{
    char data;
    cin >> data;
    while (true)
    {
        if (cin.fail())
        {
            cout << "You have entered wrong input" << endl;
            cin.clear();
            cin.ignore();
            cin >> data;
        }
        else return data;
    }
}

int input_int()
{
    int data;
    cin >> data;
    while (true)
    {
        if (cin.fail())
        {
            cout << "You have entered wrong input" << endl;
            cin.clear();
            cin.ignore();
            cin >> data;
        }
        else return data;
    }
}


int main()
{
    std::cout << "Hello, World!" << std::endl;
    int a = input_int();
    cout << a;
    return 0;
}
