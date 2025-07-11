/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* clone(Node* node, unordered_map <Node*, Node*> &mp){
        mp[node] = new Node(node->val); 
        for(Node* n: node->neighbors){
            if(mp.find(n) == mp.end()) mp[n] = clone(n, mp);
            mp[node]->neighbors.push_back(mp[n]);
        }
        return mp[node];
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map <Node*, Node*> mp;
        return clone(node, mp);
    }
};