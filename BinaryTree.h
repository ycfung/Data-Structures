//
// Created by Chingfung Yung on 11/30/2018.
//

#ifndef DATA_STRUCTURES_BINARYTREE_H
#define DATA_STRUCTURES_BINARYTREE_H


#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;


class BinaryTreeNode
{

    friend class BinaryTree;

private:

    BinaryTreeNode *leftchild;

    BinaryTreeNode *rightchild;

    char data;

public:

    char getData()
    { return data; }

    BinaryTreeNode() : leftchild(nullptr), rightchild(nullptr), data('#')
    {};

    explicit BinaryTreeNode(char s) : leftchild(nullptr), rightchild(nullptr), data(s)
    {};

};


class BinaryTree
{

public:

    BinaryTreeNode *root;

    BinaryTree() : root(nullptr)
    {};

    explicit BinaryTree(const char *str); //Level order construct

    ~BinaryTree()
    { DelNode(root); }

    bool DelNode(BinaryTreeNode *node);

    void PreOrder(BinaryTreeNode *current, string &result);

    void InOrder(BinaryTreeNode *current, string &result);

    void PostOrder(BinaryTreeNode *current, string &result);

    BinaryTreeNode *FindFather(BinaryTreeNode *node, BinaryTreeNode *current);
    //node is usually the root of tree, except when search in a subtree

    BinaryTreeNode *Search(BinaryTreeNode *node, const char &value);

};


BinaryTree::BinaryTree(const char *str)
{
    root = new BinaryTreeNode;

    queue<BinaryTreeNode *> q;

    BinaryTreeNode *current = root;

    stringstream ss;

    ss << str;

    char temp;

    ss >> root->data;

    while (ss >> temp)
    {
        if (temp >= 65 && temp <= 90)
        {
            auto *new_node = new BinaryTreeNode(temp);  // call constructor BinaryTreeNode(char s)
            current->leftchild = new_node;
            q.push(new_node);
        }

        if (!(ss >> temp))
            break;

        if (temp >= 65 && temp <= 90)
        {
            auto *new_node = new BinaryTreeNode;        // call constructor BinaryTreeNode()
            current->rightchild = new_node;
            new_node->data = temp;                    // assign data to new_node
            q.push(new_node);
        }
        current = q.front();
        q.pop();
    }

}


bool BinaryTree::DelNode(BinaryTreeNode *node)
{
    if (node == nullptr)
        return true;

    if (DelNode(node->leftchild) && DelNode(node->rightchild))
    {
        delete (node);
        return true;
    }

    else return false;
}


void BinaryTree::PreOrder(BinaryTreeNode *current, string &result)
{

    if (current)
    {
        result += current->data;
        PreOrder(current->leftchild, result);
        PreOrder(current->rightchild, result);
    }
}


void BinaryTree::InOrder(BinaryTreeNode *current, string &result)
{
    if (current)
    {
        InOrder(current->leftchild, result);
        result += current->data;
        InOrder(current->rightchild, result);
    }
}


void BinaryTree::PostOrder(BinaryTreeNode *current, string &result)
{
    if (current)
    {
        PostOrder(current->leftchild, result);
        PostOrder(current->rightchild, result);
        result += current->data;
    }

}


BinaryTreeNode *BinaryTree::FindFather(BinaryTreeNode *node, BinaryTreeNode *current)
{

    BinaryTreeNode *ptr = nullptr;

    if (node == nullptr or current == nullptr)
        return nullptr;

    if (node->leftchild == current or node->rightchild == current)
        return node;

    if ((ptr = FindFather(node->leftchild, current)) != nullptr)
        return ptr;

    else return FindFather(node->rightchild, current);

}


BinaryTreeNode *BinaryTree::Search(BinaryTreeNode *node, const char &value)
{

    BinaryTreeNode *p = nullptr;

    if (node == nullptr)
        return nullptr;

    if (node->data == value)
        return node;

    if ((p = Search(node->leftchild, value)) != nullptr)
        return p;

    else return Search(node->rightchild, value);

}

#endif //DATA_STRUCTURES_BINARYTREE_H
