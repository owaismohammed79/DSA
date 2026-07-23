struct Node {
    Node *links[2];

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* n){
        links[bit] = n;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie {
    Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int el){
            Node* node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (el >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int getMax(int num) {
            Node* node = root;
            int maxi = 0;
            for(int i = 31; i >= 0; i--){
                int bit = (num >>i) & 1;
                if(node->containsKey(1-bit)){
                    maxi = maxi | (1 << i);
                    node = node->get(1-bit);
                } else {
                    node = node->get(bit);
                }
            }
            return maxi;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0, n = nums.size();
        Trie* t = new Trie();
        for(int i =0; i < n; i++){
            t->insert(nums[i]);
        }
        for(int i =0; i < n; i++){
            maxi = max(maxi, t->getMax(nums[i]));
        }
        return maxi;
    }
};