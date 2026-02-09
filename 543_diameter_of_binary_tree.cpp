/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* curr, int* max_el){
        if(curr == NULL) return 0;
        int l = dfs(curr->left, max_el);
        int r = dfs(curr->right, max_el);
        if(l + r > *max_el) *max_el = l+r;
        return max(l, r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //Start from root node, find the longest path on the left subtree and on the right 
        //subtree, find the distance bw them, if greater than max, then update
        TreeNode* curr = root;
        int max_el = 0;
        dfs(curr, &max_el);
        return max_el;
    }
};