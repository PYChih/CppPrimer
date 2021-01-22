// Exercise 13_28
//  Given the following classes,
//  implement a default constructor and the necessary copy-control members.
#include <iostream>
#include <string>

class TreeNode {
 public:
    TreeNode();
 private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
class BinStrTree {
 public:
    BinStrTree();
 private:
        TreeNode *root;
};
