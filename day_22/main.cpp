#include <iostream>
#include <cstddef>
#include "tree_node.h"

using namespace std;


class Solution{
    public:
  		TreeNode* insert(TreeNode* root, int data) {
            if(root == NULL) {
                return new TreeNode(data);
            }
            else {
                TreeNode* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

		int maxHeight(TreeNode* TreeNode){
          //Write your code here
            if (TreeNode == NULL)
            {
                return 0;
            }
            int left_height = maxHeight(TreeNode->left);
            int right_height = maxHeight(TreeNode->right);
            int result =  left_height >  right_height ? left_height + 1: right_height + 1;
            //cout << "result -> " << result  << " left: "<< left_height << " right: "<< right_height<<endl;
            return result;
        }
        int getHeight(TreeNode* TreeNode){
           //Write your code here
            int result = maxHeight(TreeNode);
            if(result > 0)
                result--;
            return result;
        }

}; //End of Solution

int main() {
    Solution myTree;
    TreeNode* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << "tree height-> " << height << endl;
    
    cout << "level order traversal : " << endl;
    levelOrder(root);
    cout << endl;
    cout << "Tree Node dot : " << endl;
    string dot_string = levelOrderPrintToDot(root);
    cout << dot_string << endl;


    return 0;
}



