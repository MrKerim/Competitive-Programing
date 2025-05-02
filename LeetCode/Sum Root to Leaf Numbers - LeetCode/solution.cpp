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

void search(TreeNode* root, string pre,int& sum){
    if(root == nullptr) return;
    pre = pre + to_string(root->val);
    if(root->right == nullptr && root->left == nullptr) {
        sum += stoi(pre);
        return;
    }

    search(root->left,pre,sum);
    search(root->right,pre,sum);
    
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        search(root,"",res);
        return res;
    }
};