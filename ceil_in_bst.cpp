/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceilVal = -1;
        while(root){
            if(root->data == x){
                ceilVal = root->data;
                return ceilVal;
            }
            if(x > root->data){
                root = root->right;
            }else{
                ceilVal = root->data;
                root = root->left;
            }
        }
        return ceilVal;
    }
};