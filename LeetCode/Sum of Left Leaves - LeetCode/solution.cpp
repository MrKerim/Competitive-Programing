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


int search(TreeNode* root, bool isLeft){
    
    if(root->left == nullptr && root->right == nullptr){
        // leaf node

        if(isLeft) return root->val;
        
        return 0;
    }

    int sum = 0;

    if(root->left != nullptr){
        sum += search(root->left,true);
    }

    if(root->right != nullptr){
        sum += search(root->right,false);
    }

    return sum;

}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return search(root,false);
    }
};