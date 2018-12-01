//
// Created by Chingfung Yung on 12/1/2018.
//

#ifndef DATA_STRUCTURES_TREE_H
#define DATA_STRUCTURES_TREE_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class TreeNode
{

    friend class Tree;

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

};

class Tree
{

public:

    TreeNode *root;

    Tree() : root(nullptr)
    {};

    explicit Tree(const char &str);

    bool AddChild(const char &str);

    bool AddBrother(const char &str);

    bool DelNode(TreeNode *node);

    ~Tree()
    { DelNode(root); }

    void PreOrder_recursive(TreeNode *current, string &result);

    void PostOrder_recursive(TreeNode *current, string &result);

    void LevelOrder(TreeNode *current, string &result)

    void PreOrder_iterative(TreeNode *current, string &result);

    void PostOrder_iterative(TreeNode *current, string &result);

};



Tree::Tree(const char &str)
{
    root = new TreeNode(str);
}


bool Tree::AddChild(const char &str)
{

    TreeNode *ptr = root;

    while (ptr->firstChild != nullptr)
        ptr = ptr->firstChild;

    ptr->firstChild = new TreeNode(str);

    return ptr->data == str;
}

bool Tree::AddBrother(const char &str)
{

    TreeNode *ptr = root;

    while (ptr->firstChild != nullptr)
        ptr = ptr->firstChild;

    while (ptr->nextBrother != nullptr)
        ptr = ptr->nextBrother;

    ptr->nextBrother = new TreeNode(str);

    return ptr->data == str;

}

bool Tree::DelNode(TreeNode *node)
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

void Tree::PreOrder_recursive(TreeNode *current, string &result)
{

    result.clear();
    if(current == nullptr)
        return;


}


#endif //DATA_STRUCTURES_TREE_H
