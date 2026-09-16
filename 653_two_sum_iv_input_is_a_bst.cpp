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
class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(!reverse){
                node = node->left;
            }else{
                node = node->right;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if(!reverse){
            pushAll(topNode->right);
        }else{
            pushAll(topNode->left);
        }
        return topNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        BSTIterator leftIter(root, false);
        BSTIterator rightIter(root, true);

        int i = leftIter.next();
        int j = rightIter.next();

        while(i < j){
            if(i + j == k){
                return true;
            }
            if(i + j < k){
                i = leftIter.next();
            }else{
                j = rightIter.next();
            }
        }
        return false;
    }
};