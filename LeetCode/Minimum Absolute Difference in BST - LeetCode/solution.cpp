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

void search(TreeNode* root,int mn,int mx,int& min_dif){
    if(root == nullptr) return;
    if(root->val < mn) mn = root->val;
    if(root->val > mx) mx = root->val;


    if(root->val != mx) min_dif = min(min_dif, mx - root->val);
    if(root->val != mn) min_dif = min(min_dif, root->val - mn);

    search(root->left,mn,root->val,min_dif);
    search(root->right,root->val,mx,min_dif);
}

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int min_dif = INT_MAX;
        search(root,root->val,root->val,min_dif);
        return min_dif;
    }
};