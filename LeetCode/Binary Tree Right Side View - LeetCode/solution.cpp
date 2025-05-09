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

void search(TreeNode* root, vector<int>& res,
int level,int& max_level){
    if(root == nullptr) return;

    if(level>max_level){
        max_level = level;
        res.push_back(root->val);
    }

    search(root->right,res,level+1,max_level);
    search(root->left,res,level+1,max_level);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int max_level = 0;
        search(root,res,1,max_level);

        return res;
    }
};