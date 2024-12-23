class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rp = nums.size();
        int pre = nums[0];
        for(int i = 1;i<nums.size();i++){ if(nums[i]<pre){ rp = i; break;} else pre = nums[i]; }

        auto a= lower_bound(nums.begin(), nums.begin()+rp, target)-nums.begin();
        auto b= lower_bound(nums.begin()+rp, nums.end(), target)-nums.begin();

        if(a<nums.size() && nums[a] == target) return a;
        if(b<nums.size() && nums[b] == target) return b;
        return -1;

        

    return 0;
    }
};