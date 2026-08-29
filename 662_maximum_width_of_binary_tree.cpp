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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();
            unsigned int minInd = q.front().second;
            unsigned int first = 0, last = 0;

            for(int i = 0; i < size; i++) {
                unsigned int currInd = q.front().second - minInd;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = currInd;
                if(i == size - 1) last = currInd;

                if(node->left)  q.push({node->left, 2*currInd});
                if(node->right) q.push({node->right, 2*currInd + 1});
            }
            ans = max(ans, static_cast<int>(last-first+1));
        }

        return ans;
    }
};