/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* traverse(TreeNode* root, int pV, int qV){
        

        if(root->val < pV && root->val < qV) 
            return traverse(root->right,pV,qV);
        
        else if(root->val > pV && root->val > qV) 
            return traverse(root->left,pV,qV);
        
        else return root;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root,p->val,q->val);
    }
};