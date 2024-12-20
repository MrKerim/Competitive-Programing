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

int arr[16400];
int n = 0;

void traversal(TreeNode* root,int i){
    arr[i] = root->val;
    if(root->right == nullptr) {
        n = max(n,i);
        return;
    };
    traversal(root->left,2*i+1);
    traversal(root->right,2*i+2);
    return;
}

TreeNode* mergeTree(int i){
    TreeNode* templ = 2*i+1<=n ?  mergeTree(2*i + 1) : nullptr;
    TreeNode* tempr = 2*i+2<=n ?  mergeTree(2*i + 2) : nullptr;
    TreeNode* head = new TreeNode(arr[i],templ,tempr);
    return head;
    
    return templ;
}

void reverseArr(int l, int r,int depth){
    if(r>n) return;
    if(depth%2) {
    // reverse l and r inclusive
    int temp_l = l; int temp_r = r;
    while(temp_r > temp_l){
        swap(arr[temp_l],arr[temp_r]);
        temp_r--; temp_l++;
    }
    }

    reverseArr(l*2 + 1, r*2+2, depth+1);
        return;

}

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        n = 0;
        traversal(root,0);
        reverseArr(0,0,0);
        TreeNode* head = mergeTree(0);
        return head;
    }
};