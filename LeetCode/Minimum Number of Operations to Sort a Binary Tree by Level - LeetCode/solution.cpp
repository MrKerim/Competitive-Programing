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

void dfs(int level,vector<vector<pair<int,int> > >&arr,TreeNode* root){
    if(root == nullptr) return;
    if(arr.size()<=level) arr.push_back({});
    arr[level].push_back(make_pair(root->val,arr[level].size()));
    dfs(level+1,arr,root->left);
    dfs(level+1,arr,root->right);
    return;
}

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        vector<vector<pair<int,int> > > arr;
        dfs(0,arr,root); // O(n)
        for(int i = 0; i<arr.size();i++) sort(arr[i].begin(),arr[i].end()); // nlog(n)

        /*
            for(auto v:arr){
            for(auto p:v){
                cout<<"["<<p.first<<","<<p.second<<"]";
            }
            cout<<"\n";
        }
        */
        unordered_set<int> visited;
        int swapNumber = 0;
        // total of iterating n elements O(n)
        for(int i = 0;i<arr.size();i++){
            visited.clear();
            for(int j = 0; j<arr[i].size(); j++){
                if(visited.count(j) == 1) continue;

                int current = arr[i][j].second;
                visited.insert(current);
                int cycle = 1;

                cout<<j<<"->"<<current<<"->";
                while(current != j){
                    current = arr[i][current].second;
                    visited.insert(current);
                    cycle++;
                }
                swapNumber += cycle-1;
            }

        }


        return swapNumber;
    }
};