#include <iostream>

#include "Tree.h"
#include "Forest.h"
#include "TreeNode.h"

using namespace std;

int main()
{

    Tree tree;
    string str = "AB#CE#F##D##";
    tree.root = tree.Create(str);
    string result;
    LevelOrder(tree.root, result);
    cout << result << endl;
    return 0;

}
