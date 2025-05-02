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


void search(TreeNode* root,int& current_index,int left, int right,
vector<int>& postorder, unordered_map<int,int>& inorder_index
){
    int current_inorder_index = inorder_index[postorder[current_index]];

    // Right
    if(current_inorder_index < right){
        root->right = new TreeNode(postorder[current_index - 1]);
        int new_left = current_inorder_index + 1;
        
        current_index--;
        search(root->right,current_index,new_left,right,
        postorder,inorder_index);
    }

    // Left
    if(current_inorder_index > left){
        root->left = new TreeNode(postorder[current_index - 1]);
        int new_right = current_inorder_index - 1;
        
        current_index--;
        search(root->left,current_index,left,new_right,
        postorder,inorder_index);
    }



}


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.size() == 0) return nullptr;

        unordered_map<int,int> inorder_index;
        for(int i = 0; i < postorder.size();i++)
            inorder_index[inorder[i]] = i;

        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        if(postorder.size() == 1) return root;

        
        int current_index = postorder.size()-1;
        search(root,current_index,0,postorder.size()-1,
        postorder,inorder_index);

        return root;
    }
};