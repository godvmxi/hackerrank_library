#ifndef  __TREE_NODE__
#define __TREE_NODE__
#include <string>
class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int d){
            data = d;
            left = nullptr;
            right = nullptr;
        }
};
void levelOrder(TreeNode *root);
std::string levelOrderPrintToDot(TreeNode *root);


#endif