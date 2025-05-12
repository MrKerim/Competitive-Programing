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


void search(Node* node,Node* cpy ,unordered_map<int,Node*>& mp,
unordered_map<int,bool>& visited){
    visited[node->val] = true;
    for(auto n : node->neighbors){
        if(mp[n->val] == nullptr) mp[n->val] = new Node(n->val);
        cpy->neighbors.push_back(mp[n->val]);
    }

    //print(node);
    //print(cpy);

    for(int i = 0;i<node->neighbors.size();i++){
        if(!visited[node->neighbors[i]->val])
            search(node->neighbors[i],cpy->neighbors[i],mp,visited);
    }
}



class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<int,Node*> mp;
        unordered_map<int,bool> visited;
        Node* cpy = new Node(node->val);
        mp[node->val] = cpy;


        search(node,cpy,mp,visited);

        return cpy;
    }
};