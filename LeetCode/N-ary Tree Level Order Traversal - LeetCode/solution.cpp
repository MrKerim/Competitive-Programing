/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

void dfs(int level,vector<vector<int> >& arr, Node* root){
    if(root == nullptr) return;
    if(arr.size()<=level) arr.push_back({});
    arr[level].push_back(root->val);
    for(auto c : root->children){
        dfs(level+1,arr,c);
    }
    return;

}


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        dfs(0,res,root);
        return res;
    }
};