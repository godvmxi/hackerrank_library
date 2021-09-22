#include <iostream>
#include <cstddef>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
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

		int maxHeight(Node* node){
          //Write your code here
            if (node == NULL)
            {
                return 0;
            }
            int left_height = maxHeight(node->left);
            int right_height = maxHeight(node->right);
            int result =  left_height >  right_height ? left_height + 1: right_height + 1;
            //cout << "result -> " << result  << " left: "<< left_height << " right: "<< right_height<<endl;
            return result;
        }
        int getHeight(Node* node){
           //Write your code here
            int result = maxHeight(node);
            if(result > 0)
                result--;
            return result;
        }

}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}



