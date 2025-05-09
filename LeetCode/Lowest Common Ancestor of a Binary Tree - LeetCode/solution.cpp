/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool search(TreeNode* root,int p,vector<int>& vec_p){
    if(root==nullptr) return false;
    if(root->val == p){
        vec_p.push_back(p);
        return true;
    }

    if(search(root->left,p,vec_p) || search(root->right,p,vec_p)){
        vec_p.push_back(root->val);
        return true;
    }
    return false;
}

TreeNode* find(TreeNode* root,vector<int>& res , int n){

    if(n == -1) return root;

    int target = res[n];
    if(root->left != nullptr && (root->left->val == target))
        return find(root->left,res,n-1);
    else return find(root->right,res,n-1);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> vec_p;
        vector<int> vec_q;
        search(root,p->val,vec_p);
        search(root,q->val,vec_q);

        vector<int> res;

        int p_index = 0;
        int q_index = 0;

        if(vec_p.size() < vec_q.size())
            q_index = vec_q.size() - vec_p.size();
        else if(vec_p.size() > vec_q.size())
            p_index = vec_p.size() - vec_q.size();

        while(vec_p[p_index] != vec_q[q_index]){
            p_index++;
            q_index++;
        }



        while(p_index < vec_p.size()){
            res.push_back(vec_p[p_index]);
            p_index++;
        }


        return find(root,res,res.size()-2);
    }
};