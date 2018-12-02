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


class Forest :
{

private:

    TreeNode *root;

public:

    Forest() : root(nullptr)
    {};

    bool AddTree(string &str);

};

bool Forest::AddTree(string &str)
{

    Tree *tree = new Tree();
    TreeNode *ptr = tree->Create(str);
    TreeNode *temp = root;

    if (this->root == nullptr)
    {
        root = new TreeNode();
        root->firstChild = ptr;
        return true;
    }

    else if (ptr != nullptr)
    {
        while (temp->nextBrother != nullptr)
            temp = temp->nextBrother;
        temp->nextBrother = ptr;
        return true;
    }

    else return false;
}


#endif //DATA_STRUCTURES_FOREST_H
