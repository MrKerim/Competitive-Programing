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
 
class Solution {
public:

    vector<TreeNode*> search(int left,int right){
        vector<TreeNode*> result;

        if(left == right){
            TreeNode* newTree = new TreeNode(left);
            result.push_back(newTree);
            return result;
        }

        if(left>right){
            result.push_back(nullptr);
            return result;
        }
            

        

        for(int val = left; val<=right; val++) {

            for(TreeNode* leftNode : search(left,val-1))
            {
                for(TreeNode* rightNode: search(val+1,right))
                {
                    TreeNode* newTree = new TreeNode(val,leftNode,rightNode);
                    result.push_back(newTree);
                }
            }

        }

        return result;

    }

    vector<TreeNode*> generateTrees(int n) {
        return search(1,n);   
    }
};