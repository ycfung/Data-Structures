//
// Created by Chingfung Yung on 12/1/2018.
//

#ifndef DATA_STRUCTURES_FOREST_H
#define DATA_STRUCTURES_FOREST_H

#include <iostream>
#include <string>
#include "TreeNode.h"
#include "Tree.h"

using namespace std;


class Forest
{

private:

    TreeNode *root;

public:

    TreeNode *getRoot()
    { return this->root; }

    Forest()
    { root = new TreeNode('#'); };

    ~Forest()
    { DelNode(root); }

    bool AddTree(string &str);

    friend void PreOrder_recursive(TreeNode *current, string &result);

    friend void PostOrder_recursive(TreeNode *current, string &result);

    friend void LevelOrder(TreeNode *current, string &result);

    friend void PreOrder_iterative(TreeNode *current, string &result);

    friend void PostOrder_iterative(TreeNode *current, string &result);

};


bool Forest::AddTree(string &str)
{

    Tree tree;
    TreeNode *ptr = tree.Create(str);
    TreeNode *temp = root->firstChild;

    if (root->firstChild == nullptr)
    {
        root->firstChild = ptr;
        return true;
    }

    else
    {
        while (temp->nextBrother != nullptr)
            temp = temp->nextBrother;
        temp->nextBrother = ptr;
        return true;
    }

}


#endif //DATA_STRUCTURES_FOREST_H
