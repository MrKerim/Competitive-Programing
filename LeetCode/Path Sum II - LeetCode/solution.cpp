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


void search(TreeNode* root,
    unordered_map<TreeNode* ,TreeNode* >& parent,
    vector<TreeNode*>& result,
    int previous,
    int target

    ){

        if(root->left == nullptr && root->right == nullptr) {
            if(root->val + previous != target) return;
            result.push_back(root);
        }


        if(root->left != nullptr) {
            parent[root->left] = root;
            search(
                root->left,
                parent,
                result,
                previous + root->val,
                target
            );
        }

        if(root->right != nullptr) {
            parent[root->right] = root;
            search(
                root->right,
                parent,
                result,
                previous + root->val,
                target
            );
        }


}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int> > result;
        if(root == nullptr) return result;

        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = nullptr;


        vector<TreeNode*> leafs;
        search(
                root,
                parent,
                leafs,
                0,
                targetSum
            );

        for(TreeNode* leaf : leafs){
            deque<int> path;
            vector<int> pathResult;

            TreeNode* current = leaf;
            while(current != nullptr){
                path.push_front(current->val);
                current = parent[current];
            }

            for(int x : path){
                pathResult.push_back(x);
            }

            result.push_back(pathResult);
        }

        

        return result;
    }
};