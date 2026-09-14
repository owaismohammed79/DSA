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
    int inOrderSuccessor(Node *root, Node *k) {
        int successor = -1;
        while(root){
            if(k->data < root->data){
                successor = root->data;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return successor;
    }
};