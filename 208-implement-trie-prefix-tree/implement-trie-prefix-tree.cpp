class Node {

public:

    Node* links[26];
    bool isEnd;

    Node() {

        for(int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }

        isEnd = false;
    }

};
class Trie {

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {

        Node* node = root;

        int len = word.length();
        for(int i = 0; i < len; i++) {

            if(node->links[word[i] - 'a'] == nullptr) {

                node->links[word[i] - 'a'] = new Node();
            } 

            node = node->links[word[i] - 'a'];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;

        int len = word.length();
        for(int i = 0; i < len; i++) {

            if(node->links[word[i] - 'a'] == nullptr) {

                return false;
            } 

            node = node->links[word[i] - 'a'];
        }

        return node->isEnd ;
    }
    
    bool startsWith(string prefix) {
        
        Node* node = root;

        int len = prefix.length();
        for(int i = 0; i < len; i++) {

            if(node->links[prefix[i] - 'a'] == nullptr) {

                return false;
            } 

            node = node->links[prefix[i] - 'a'];
        }

        return true;

    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */