/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeHelper(TreeNode* root, string& result) {
        if(!root) {
            result += "#,";
            return;
        }
        result += to_string(root->val) + ",";
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    TreeNode* deserializeHelper(const string& data, int& index) {
        if(index >= data.size()) return nullptr;

        int nextComma = data.find(',', index);
        if(nextComma == string::npos) return nullptr;
        string token = data.substr(index, nextComma - index);
        index = nextComma + 1;
        if(token == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(data, index);
        root->right = deserializeHelper(data, index);

        return root;
    }

public:
    string serialize(TreeNode* root) {
        string result = "";
        serializeHelper(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeHelper(data, index);
    }
};