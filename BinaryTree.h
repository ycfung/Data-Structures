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

class TreeNode
{
    friend class BinaryTree;

private:

    TreeNode *leftchild;

    TreeNode *rightchild;

    char data;

public:

    TreeNode() : leftchild(nullptr), rightchild(nullptr), data('#')
    {};

    explicit TreeNode(char s) : leftchild(nullptr), rightchild(nullptr), data(s)
    {};

};

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree() : root(nullptr)
    {};

    explicit BinaryTree(const char *str); //Level order construct

    ~BinaryTree()
    { DelNode(root); }

    bool DelNode(TreeNode *node);

    void PreOrder(TreeNode *current, string &result);

    void InOrder(TreeNode *current, string &result);

    void PostOrder(TreeNode *current, string &result);


};


BinaryTree::BinaryTree(const char *str)
{
    root = new TreeNode;
    queue<TreeNode *> q;
    TreeNode *current = root;
    stringstream ss;
    ss << str;
    char temp;
    ss >> root->data;
    while (ss >> temp)
    {
        if (temp >= 65 && temp <= 90)
        {
            auto *new_node = new TreeNode(temp);  // call constructor TreeNode(char s)
            current->leftchild = new_node;
            q.push(new_node);
        }

        if (!(ss >> temp))
            break;

        if (temp >= 65 && temp <= 90)
        {
            auto *new_node = new TreeNode;        // call constructor TreeNode()
            current->rightchild = new_node;
            new_node->data = temp;                    // assign data to new_node
            q.push(new_node);
        }
        current = q.front();
        q.pop();
    }
}

bool BinaryTree::DelNode(TreeNode *node)
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

void BinaryTree::PreOrder(TreeNode *current, string &result)
{
    if (current)
    {
        result = result + current->data;
        PreOrder(current->leftchild, result);
        PreOrder(current->rightchild, result);
    }
}

void BinaryTree::InOrder(TreeNode *current, string &result)
{
    if (current)
    {
        InOrder(current->leftchild, result);
        result = result + current->data;
        InOrder(current->rightchild, result);
    }
}

void BinaryTree::PostOrder(TreeNode *current, string &result)
{
    if (current)
    {
        PostOrder(current->leftchild, result);
        PostOrder(current->rightchild, result);
        result = result + current->data;
    }
}

#endif //DATA_STRUCTURES_BINARYTREE_H
