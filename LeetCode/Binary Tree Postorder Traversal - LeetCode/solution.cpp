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

void search(vector<int>& result, TreeNode* root){
    
    if(root == nullptr) return;

    search(result, root->left);
    search(result, root->right);

    result.push_back(root->val);

}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        search(result, root);

        return result;
    }
};