//
// Created by Chingfung Yung on 12/2/2018.
//

#ifndef DATA_STRUCTURES_TREENODE_H
#define DATA_STRUCTURES_TREENODE_H


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

#endif //DATA_STRUCTURES_TREENODE_H
