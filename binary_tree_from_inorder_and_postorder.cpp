/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
private:
    Node* buildTreeHelper(const vector<int>& inorder, int inStart, int inEnd, const vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMap) {
        if(inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        Node* root = new Node(postorder[postEnd]);

        int inRoot = inMap[root->data];
        int numsLeft = inRoot - inStart;
        
        root->left = buildTreeHelper(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);

        root->right = buildTreeHelper(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);

        return root;
    }

public:
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
    }
};