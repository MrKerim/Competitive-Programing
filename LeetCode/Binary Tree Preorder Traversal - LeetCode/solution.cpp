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

void search(TreeNode* root, vector<int>& result){

    if(root == nullptr) return;

    result.push_back(root->val);
    search(root->left,result);
    search(root->right,result);
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        search(root,result);

        return result;

    }
};