vector<vector<int> > res;


void rec(int i,vector<int> pre,int sum,vector<int>&nums,int target){
    if(i>=nums.size()) return;
    if(sum + nums[i] > target) return;
    pre.push_back(nums[i]);
    if(sum + nums[i] == target) {
        res.push_back(pre);
        return;
    }



    for(int j = 0;j<nums.size();j++){
        rec(i+j,pre,sum+nums[i],nums,target);
    }
    //rec(i,pre,sum+nums[i],nums,target);
    //rec(i+1,pre,sum+nums[i],nums,target);
    return;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.resize(0);
        vector<int> temp;

        for(int i = 0;i<candidates.size();i++){
            rec(i,temp,0,candidates,target);
        }
        return res;
    }
};