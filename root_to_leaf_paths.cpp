/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void dfs(Node* node, vector<int>& currPath, vector<vector<int>>& result) {
        if(node == nullptr) return;
        currPath.push_back(node->data);
    
        if(node->left == nullptr && node->right == nullptr) {
            result.push_back(currPath);
        } else {
            dfs(node->left, currPath, result);
            dfs(node->right, currPath, result);
        }
    
        currPath.pop_back();
    }
    vector<vector<int>> paths(Node* root) {
        vector<int> currPath;
        vector<vector<int>> result;
        dfs(root, currPath, result);
        return result;
    }
};