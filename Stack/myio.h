//
// Created by Chingfung Yung on 11/26/2018.
//

#ifndef LINKEDLIST_MYIO_H
#define LINKEDLIST_MYIO_H

#include <iostream>
#include <string>
using namespace std;

string input_string()
{
    string data;
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
#endif //LINKEDLIST_MYIO_H
