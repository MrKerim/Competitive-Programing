class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        auto a = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        auto b = upper_bound(nums.begin(), nums.end(), target)-nums.begin();

        if(a<nums.size() && nums[a] == target) res.push_back(a);
        else return {-1,-1};
        res.push_back(b-1);
        return res;
    }
};