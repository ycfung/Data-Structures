#include <iostream>

#include "Tree.h"
#include "Forest.h"
#include "TreeNode.h"
#include "BinaryTree.h"
#include "Sorting.h"

using namespace std;

int main()
{

/*
    char *str = const_cast<char *>("ABCD#EF");

    string PreOrder_result, InOrder_result, PostOrder_result;

    BinaryTree tree(str);

    tree.PreOrder(tree.getRoot(), PreOrder_result);

    tree.InOrder(tree.getRoot(), InOrder_result);

    tree.PostOrder(tree.getRoot(), PostOrder_result);

    cout << "Pre order: " << PreOrder_result << endl;

    cout << "In order: " << InOrder_result << endl;

    cout << "Post order: " << PostOrder_result << endl;

    Tree tree;

    string str = "AB#CE#F##D##";

    tree.Create(str);

    string LevelOrderResult, PreOrderResult1, PreOrderResult2, PostOrderResult1, PostOrderResult2;

    PreOrder_recursive(tree.getRoot(), PreOrderResult1);

    PreOrder_iterative(tree.getRoot(), PreOrderResult2);

    cout << "Pre order recursive: " << PreOrderResult1 << endl;

    cout << "Pre order iterative: " << PreOrderResult2 << endl;

    PostOrder_recursive(tree.getRoot(), PostOrderResult1);

    PostOrder_iterative(tree.getRoot(), PostOrderResult2);

    cout << "Post order recursive: " << PostOrderResult1 << endl;

    cout << "Post order iterative: " << PostOrderResult2 << endl;

    LevelOrder(tree.getRoot(), LevelOrderResult);

    cout << "Level order: " << LevelOrderResult << endl;





    Forest forest;

    string str1 = "AB#CE#F##D##";

    string str2 = "CD#AB#E##F##";

    string result1, result2, result3, result4, result5;

    forest.AddTree(str1);

    forest.AddTree(str2);

    PreOrder_recursive(forest.getRoot(), result1);

    PreOrder_iterative(forest.getRoot(), result2);

    PostOrder_recursive(forest.getRoot(), result3);

    PostOrder_iterative(forest.getRoot(), result4);

    LevelOrder(forest.getRoot(), result5);

    cout << result1 << endl << result2 << endl << result3 << endl << result4 << endl << result5 << endl;

    return 0;
*/


    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    QuickSort(arr, 0, 9);
    for (auto ptr:arr)
        cout << ptr << ' ' << endl;

}
