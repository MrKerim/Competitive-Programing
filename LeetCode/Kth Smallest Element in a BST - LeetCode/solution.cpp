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

void search(TreeNode* root,int& k,int& res){
    if(root == nullptr) return;
    search(root->left,k,res);
    if(k == 1){
        k--;
        res = root->val;
        return;
    }
    k--;
    search(root->right,k,res);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        search(root,k,res);
        return res;
    }
};