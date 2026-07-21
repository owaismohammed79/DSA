/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char c){
        return (links[c - 'a'] != NULL);
    }

    void put(char c, Node* n){
        links[c-'a'] = n;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void setEnd(){
        flag= true;
    }

    bool isEnded(){
        return flag;
    }
};


class Trie {
private: Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(char c: word){
            if(!node->containsKey(c)){
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        //Can I use this instead of the setEnd function??
        node->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(char c: word){
            if(!node->containsKey(c)) return false;
            node = node->get(c);
        }
        if(!node->isEnded()) return false;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c: prefix){
            if(!node->containsKey(c)) return false;
            node = node->get(c);
        }
        return true;
    }
};