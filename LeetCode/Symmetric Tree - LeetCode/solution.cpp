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

bool search(TreeNode* l,TreeNode* r){
    if(l==nullptr ^ r==nullptr) return false;
    if(l==nullptr) return true;
    if(l->val != r->val) return false;

    return search(l->left,r->right) * search(l->right,r->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return search(root->left,root->right);
    }
};