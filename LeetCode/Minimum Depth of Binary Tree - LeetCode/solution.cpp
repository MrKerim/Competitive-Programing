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

int search(TreeNode* root){
    if(root == nullptr) return 0;
    if(root->left == nullptr ^ root->right==nullptr)
    return max(search(root->left),search(root->right)) +1;

    return min(search(root->left),search(root->right)) +1;
}

class Solution {
public:
    int minDepth(TreeNode* root) {
        return search(root);
    }
};