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

int search(TreeNode* root, bool& result){
    if(root == nullptr) return 1;

    int left = search(root->left,result) ;
    int right = search(root->right,result);

    if(left == right || left == right - 1 || left == right + 1){
        return max(left,right) + 1;
    }

    result = false;
    return 0;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        bool result = true;
        search(root,result);

        return result;
    }
};