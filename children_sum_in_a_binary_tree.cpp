/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // Base cases: NULL tree or leaf nodes are valid by default
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        int childSum = 0;
        if (root->left != nullptr) {
            childSum += root->left->data;
        }
        if (root->right != nullptr) {
            childSum += root->right->data;
        }

        // Validate current node's sum and recursively check both subtrees
        return (root->data == childSum) 
            && isSumProperty(root->left) 
            && isSumProperty(root->right);
    }
};