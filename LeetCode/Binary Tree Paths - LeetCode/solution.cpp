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


void search(vector<string >& result,string previous , TreeNode* root){

    previous += to_string(root->val);

    if(root->left == nullptr && root->right == nullptr){
        result.push_back(previous);
        return;
    }

    previous += "->";

    if(root->left != nullptr){
                
        search(result, previous, root->left);
    }

    if(root->right != nullptr){

        search(result, previous, root->right);
    }
    
}


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string > result;
        string previous;
        search(result,previous,root);

        return result;
    }
};