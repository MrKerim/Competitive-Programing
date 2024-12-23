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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        dfs(0,res,root);
        return res;
    }
};