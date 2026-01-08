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
class Solution {
public:

    bool solveSubTree(TreeNode* root){
        
        // BAse case sheshore emoji exist
        if(root->val == 0 || root->val == 1){
            return root->val;
        }

        bool left = solveSubTree(root->left);
        bool right = solveSubTree(root->right);

        if(root->val == 2) return (left || right);
        else return (left && right);
    }

    bool evaluateTree(TreeNode* root) {
        return solveSubTree(root);
    }
};