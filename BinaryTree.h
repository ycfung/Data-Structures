//
// Created by Chingfung Yung on 11/30/2018.
//

#ifndef DATA_STRUCTURES_BINARYTREE_H
#define DATA_STRUCTURES_BINARYTREE_H

#include <iostream>
#include <sstream>
#include <queue>


class BinaryTree;

class TreeNode
{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    char data;
public:
    TreeNode() : leftchild(nullptr), rightchild(nullptr), parent(nullptr), data('x')
    {};

    explicit TreeNode(char s) : leftchild(nullptr), rightchild(nullptr), parent(nullptr), data(s)
    {};

    friend class BinaryTree;
};

class BinaryTree
{
private:
    TreeNode *root;
public:
    BinaryTree() : root(nullptr)
    {};

    explicit BinaryTree(const char *str);

    void LevelorderConstruct(std::stringstream &ss);

    void InsertLevelOrder(char data);

    TreeNode *leftmost(TreeNode *current);

    TreeNode *InorderSuccessor(TreeNode *current);

    void Inorder_by_parent();
};

BinaryTree::BinaryTree(const char *str)
{
    std::stringstream ss;
    ss << str;

    root = new TreeNode;
    ss >> root->data;

    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(std::stringstream &ss)
{

    std::queue<TreeNode *> q;         // create a queue to handle level-roder rule
    TreeNode *current = root;        // point *current to root
    char data = 'x';                 // initialize data as 'x'

    while (ss >> data)
    {
        if (data >= 65 && data <= 90)
        {
            auto *new_node = new TreeNode(data);  // call constructor TreeNode(char s)
            new_node->parent = current;
            current->leftchild = new_node;
            q.push(new_node);
        }
        if (!(ss >> data))
        {
            break;
        }
        if (data >= 65 && data <= 90)
        {
            auto *new_node = new TreeNode;        // call constructor TreeNode()
            new_node->parent = current;
            current->rightchild = new_node;
            new_node->data = data;                    // assign data to new_node
            q.push(new_node);
        }
        current = q.front();                          // 從queue中更新current
        q.pop();                                      // 更新queue
    }
}

void BinaryTree::InsertLevelOrder(char data)
{

    std::queue<TreeNode *> q;
    TreeNode *current = root;

    while (current)
    {
        if (current->leftchild != nullptr)
        {
            q.push(current->leftchild);
        }
        else
        {
            auto *new_node = new TreeNode(data);
            new_node->parent = current;
            current->leftchild = new_node;
            break;
        }
        if (current->rightchild != nullptr)
        {
            q.push(current->rightchild);
        }
        else
        {
            auto *new_node = new TreeNode(data);
            new_node->parent = current;
            current->rightchild = new_node;
            break;
        }
        current = q.front();
        q.pop();
    }
}

TreeNode *BinaryTree::leftmost(TreeNode *current)
{
    while (current->leftchild != nullptr)
    {
        current = current->leftchild;
    }
    return current;
}

TreeNode *BinaryTree::InorderSuccessor(TreeNode *current)
{
    if (current->rightchild != nullptr)
    {
        return leftmost(current->rightchild);
    }


    TreeNode *successor = current->parent;
    while (successor != nullptr && current == successor->rightchild)
    {
        current = successor;
        successor = successor->parent;
    }
    return successor;
}

void BinaryTree::Inorder_by_parent()
{
    auto *current = new TreeNode;
    current = leftmost(root);

    while (current)
    {
        std::cout << current->data << " ";
        current = InorderSuccessor(current);
    }
}


#endif //DATA_STRUCTURES_BINARYTREE_H

