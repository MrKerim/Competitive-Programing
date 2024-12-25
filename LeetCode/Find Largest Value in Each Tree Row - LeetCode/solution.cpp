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

void dfs(int level,TreeNode* root,vector<int>&maxRow){
    if(root == nullptr) return;
    if(maxRow.size()<=level) maxRow.push_back(root->val);
    else maxRow[level] = max(maxRow[level],root->val);
    dfs(level+1,root->left,maxRow);
    dfs(level+1,root->right,maxRow);
    return;
}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxRow;
        dfs(0,root,maxRow);
        return maxRow;
    }
};