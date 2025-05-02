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

void search(TreeNode* node){
    if(node == nullptr) return;
    TreeNode* temp = node->right;
    node->right = node->left;
    node->left = temp;

    search(node->left);
    search(node->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        search(root);
        return root;
    }
};