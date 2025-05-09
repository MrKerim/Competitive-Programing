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

bool search(TreeNode* root,long long mn,long long mx){
    if(root == nullptr) return true;
    if(root->val >= mx || root->val <= mn) return false;

    bool left = search(root->left,mn,root->val);
    bool right = search(root->right,root->val,mx);

    return left && right;

}   

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return search(root,LLONG_MIN,LLONG_MAX);
    }
};