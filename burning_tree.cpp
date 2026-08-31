/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
private:
    Node* mapParentsAndFindTarget(Node* root, int target, unordered_map<Node*, Node*>& parentMap) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if(curr->data == target) {
                targetNode = curr;
            }

            if(curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }

public:
    int minTime(Node* root, int target) {
        if(!root) return 0;

        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = mapParentsAndFindTarget(root, target, parentMap);

        if(!targetNode) return 0;

        queue<Node*> q;
        unordered_set<Node*> visited;

        q.push(targetNode);
        visited.insert(targetNode);

        int totalTime = 0;

        while(!q.empty()) {
            int size = q.size();
            bool fireSpreadThisSecond = false;

            for(int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if(curr->left && !visited.count(curr->left)) {
                    fireSpreadThisSecond = true;
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                if(curr->right && !visited.count(curr->right)) {
                    fireSpreadThisSecond = true;
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                if(parentMap.count(curr) && !visited.count(parentMap[curr])) {
                    fireSpreadThisSecond = true;
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }

            if(fireSpreadThisSecond) {
                totalTime++;
            }
        }

        return totalTime;
    }
};