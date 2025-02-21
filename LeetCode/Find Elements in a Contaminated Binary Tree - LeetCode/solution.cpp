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
class FindElements {
    TreeNode* tree;
public:
    FindElements(TreeNode* root) {
        recover(root,0);
        tree = root;
    }

    void recover(TreeNode* root, int val){
        root->val = val;
        if(root->left != nullptr) recover(root->left,val*2 + 1);
        if(root->right != nullptr) recover(root->right,val*2 + 2);
    }

    
    bool find(int target) {
        stack<bool> st;
        while(target > 0) {
            if(target%2 == 0){
                st.push(true);
                target = (target - 2)/2;
            }   
            else{
                //odd left (false)
                st.push(false);
                target = (target -1 )/2;
            }
        }

        TreeNode* temp = tree;
        while(!st.empty()){
            if(st.top()){
                //right
                if(temp->right == nullptr) return false;
                st.pop();
                temp = temp-> right;
            }
            else{
                //left
                if(temp->left == nullptr) return false;
                st.pop();
                temp = temp-> left;
            }
        }

        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */