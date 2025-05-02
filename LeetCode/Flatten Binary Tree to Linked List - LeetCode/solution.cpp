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

void search(TreeNode* root,TreeNode*& LL){
    LL -> right = new TreeNode(root->val);
    LL = LL-> right;
    if(root->left != nullptr) search(root->left,LL);
    if(root->right != nullptr) search(root->right,LL);
}

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* res = new TreeNode(root->val);
        TreeNode* temp = res;
        search(root,temp);
        res = res->right;

        while(res != nullptr){
            root->val = res->val;
            root->left = nullptr;

            if(root->right == nullptr && res->right != nullptr) root->right = new TreeNode();
            root = root->right;
            res = res -> right;
        }
        
    }
};