//
// Created by Chingfung Yung on 12/2/2018.
//

#ifndef DATA_STRUCTURES_TREENODE_H
#define DATA_STRUCTURES_TREENODE_H
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;


class TreeNode
{

    friend class Tree;

    friend class Forest;

public:

    char data;

    TreeNode *firstChild;

    TreeNode *nextBrother;

    char getData()
    { return data; }

    TreeNode() : firstChild(nullptr), nextBrother(nullptr), data('#')
    {};

    explicit TreeNode(const char s) : firstChild(nullptr), nextBrother(nullptr), data(s)
    {};

    //bool AddChild(const char &str);

    //bool AddBrother(const char &str);



};


void PreOrder_recursive(TreeNode *current, string &result)
{

    if (current != nullptr)
    {
        result += current->data;
        TreeNode *ptr = nullptr;
        ptr = current->firstChild;
        while (ptr != nullptr)
        {
            PreOrder_recursive(ptr, result);
            ptr = ptr->nextBrother;
        }
    }



}

void PostOrder_recursive(TreeNode *current, string &result)
{


    if (current != nullptr)
    {
        TreeNode *ptr = nullptr;
        ptr = current->firstChild;
        while (ptr != nullptr)
        {
            PostOrder_recursive(ptr, result);
            ptr = ptr->nextBrother;
        }
        result += current->data;
    }


}

void PreOrder_iterative(TreeNode *current, string &result)
{

    if (current == nullptr)
        return;

    stack<TreeNode *> s;
    TreeNode *ptr = current;

    do
    {

        while (ptr != nullptr)
        {
            result += ptr->data;
            s.push(ptr);
            ptr = ptr->firstChild;
        }

        while (ptr == nullptr && (!s.empty()))
        {
            ptr = s.top();
            s.pop();
            ptr = ptr->nextBrother;
        }

    } while (!s.empty());


}

void PostOrder_iterative(TreeNode *current, string &result)
{

    if (current == nullptr)
        return;

    stack<TreeNode *> s;
    TreeNode *ptr = current;
    do
    {
        while (ptr != nullptr)
        {
            s.push(ptr);
            ptr = ptr->firstChild;
        }
        while (ptr == nullptr && !s.empty())
        {
            ptr = s.top();
            s.pop();
            result += ptr->data;
            ptr = ptr->nextBrother;
        }
    } while (!s.empty());


}

void LevelOrder(TreeNode *current, string &result)
{
    queue<TreeNode *> q;
    if (current != nullptr)
    {
        TreeNode *ptr;
        q.push(current);
        while (!q.empty())
        {
            ptr = q.front();
            q.pop();
            result += ptr->data;
            ptr = ptr->firstChild;
            while (ptr != nullptr)
            {
                q.push(ptr);
                ptr = ptr->nextBrother;
            }
        }
    }


}


//will generate raw pointer here
bool DelNode(TreeNode *node)
{

    if (node == nullptr)
        return true;

    if (DelNode(node->firstChild) or DelNode(node->nextBrother))
    {
        delete (node);
        return true;
    }

    else return false;

}


#endif //DATA_STRUCTURES_TREENODE_H
