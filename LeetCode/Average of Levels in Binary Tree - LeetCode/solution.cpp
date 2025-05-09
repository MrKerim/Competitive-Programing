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

void search(TreeNode* root,int level,vector<long long>& vec,vector<int>& num){
    if(root == nullptr) return;

    vec[level] += root->val;
    num[level]++;
    search(root->left,level+1,vec,num);
    search(root->right,level+1,vec,num);
}

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long long> vec(10200,0);
        vector<int> num(10200,0);

        search(root,0,vec,num);

        vector<double> res;
        
        int i = 0;
        while(num[i] != 0){
            res.push_back(((double) vec[i])/num[i]);
            i++;
        }

        return res;
    }
};