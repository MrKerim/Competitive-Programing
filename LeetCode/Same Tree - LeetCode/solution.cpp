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

bool search(TreeNode* p,TreeNode*q){
    if(p==nullptr ^ q==nullptr) return false;
    if(p == nullptr) return true;
    if(p->val != q->val) return false;
    
    return search(p->left,q->left) * search(p->right,q->right);
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return search(p,q);
    }
};