//
// Created by Chingfung Yung on 12/1/2018.
//

#ifndef DATA_STRUCTURES_TREE_H
#define DATA_STRUCTURES_TREE_H

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Tree
{
private:

    TreeNode *root;

public:

    TreeNode *getRoot()
    { return this->root; }

    Tree() : root(nullptr)
    {};

    explicit Tree(const char &str);


    friend bool DelNode(TreeNode *node);

    ~Tree()
    { DelNode(root); }

    friend void PreOrder_recursive(TreeNode *current, string &result);

    friend void PostOrder_recursive(TreeNode *current, string &result);

    friend void LevelOrder(TreeNode *current, string &result);

    friend void PreOrder_iterative(TreeNode *current, string &result);

    friend void PostOrder_iterative(TreeNode *current, string &result);

    TreeNode *Create(string &str);


};


Tree::Tree(const char &str)
{
    root = new TreeNode(str);
}


TreeNode *Tree::Create(string &str)
{

    TreeNode *t, *t1, *t2;
    char m = str.front();
    str.erase(0, 1);

    if (m == '#')
    {
        t = nullptr;
        return t;
    }

    else
    {
        if ((int) m == 0)
            return nullptr;

        if ((t = new TreeNode(m)) != nullptr)
        {
            t->data = m;
            t1 = Create(str);
            t->firstChild = t1;
            t2 = Create(str);
            t->nextBrother = t2;
            this->root = t;
            return t;
        }

        else return nullptr;
    }

}

/*
bool TreeNode::AddChild(const char &str)
{

    if (this->firstChild == nullptr)
    {
        this->firstChild = new TreeNode(str);
        return true;
    }

    else return false;

}

bool TreeNode::AddBrother(const char &str)
{

    if (this->nextBrother == nullptr)
    {
        this->nextBrother = new TreeNode(str);
        return true;
    }

    else return false;

}
*/

#endif //DATA_STRUCTURES_TREE_H
