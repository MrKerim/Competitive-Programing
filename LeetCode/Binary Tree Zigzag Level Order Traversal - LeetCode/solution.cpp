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

void dfs(int level,vector<vector<int> >&arr,TreeNode* root){
    if(root == nullptr) return;
    if(arr.size()<=level) arr.push_back({});
    arr[level].push_back(root->val);
    dfs(level+1,arr,root->left);
    dfs(level+1,arr,root->right);
    return;
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > arr;
        dfs(0,arr,root);
        for(int i = 0;i<arr.size();i++){
            if(i%2 == 1) reverse(arr[i].begin(),arr[i].end());
        }

        return arr;
    }
};