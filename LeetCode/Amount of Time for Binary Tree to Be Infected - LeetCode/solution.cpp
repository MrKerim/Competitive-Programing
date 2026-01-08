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

    // If a side is effected we need distence to the patient
    // if if not we need distence to the max dis
    // We also need to store the current max val

    int findMaxDis(TreeNode* root){
        
        if(root == nullptr) return 0;

        return (
            max(
                findMaxDis(root->left),
                findMaxDis(root->right)
            ) + 1
        );


    }

    pair<int,bool> infect(
        TreeNode* root,
        int patientZero,
        int& currentMax
    ){
        // BASE
        if(root == nullptr) return make_pair(0,false);

        if(root->val == patientZero){
            int result = findMaxDis(root) - 1;

            currentMax = max(currentMax,result);

            return make_pair(1,true);
        }

        pair<int, bool> leftResult = infect(root->left,patientZero,currentMax);
        pair<int, bool> rightResult = infect(root->right,patientZero,currentMax);


        // if onse side is effected calculate max and return the infected side lenfgt
        if(
            leftResult.second || rightResult.second 
        )
        {
            currentMax = max(currentMax, leftResult.first + rightResult.first);
            
            if(leftResult.second) return make_pair(leftResult.first + 1, true);
            else return make_pair(rightResult.first + 1, true);
        }

        // if no side is infected just return the max side
        if(rightResult.first > leftResult.first){
            return make_pair(rightResult.first + 1,false);
        }
        else return make_pair(leftResult.first + 1,false);
        
        
    }



    int amountOfTime(TreeNode* root, int start) {
        int result = 0;
        infect(root,start,result);

        return result;
    }
};