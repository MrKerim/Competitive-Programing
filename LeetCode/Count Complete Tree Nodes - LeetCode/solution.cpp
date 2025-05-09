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

bool check(TreeNode* root,int level,int height){
    if(level == height && root == nullptr) return false;
    if(level == height && root != nullptr) return true;

    return check(root->left,level+1,height);
}

int search(TreeNode* root, int level,int height,int left,int right){
    if(level == height) return left;

    if(check(root->right,level+1,height))
    return search(root->right,level+1,height,left + (right-left + 1)/2,right);

    return search(root->left,level+1,height,left,right-(right-left+1)/2);

}


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* temp = root;

        int height = 0;
        while(temp != nullptr){temp = temp->left; height++;}

        return search(root,1,height,1,pow(2,height-1)) + pow(2,height-1)-1;

    }
};