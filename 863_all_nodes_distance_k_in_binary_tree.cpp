/**
 * Definition fora binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void populateParents(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if(!curr) return;
        if(parent) {
            parentMap[curr] = parent;
        }
        populateParents(curr->left, curr, parentMap);
        populateParents(curr->right, curr, parentMap);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target) return {};
        unordered_map<TreeNode*, TreeNode*> parentMap;
        populateParents(root, nullptr, parentMap);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int currentDistance = 0;
        while(!q.empty()) {
            int size = q.size();

            if(currentDistance == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parentMap.count(node) && !visited.count(parentMap[node])) {
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
            currentDistance++;
        }

        return {};
    }
};