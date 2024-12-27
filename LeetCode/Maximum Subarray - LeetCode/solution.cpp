class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefix(nums.size()+1,0);

        for(int i = 0;i<nums.size();i++)
        prefix[i+1] = prefix[i] + nums[i];

        int min_val = 0;
        int max_sum = INT_MIN;

        for(int i = 1;i<prefix.size();i++){
            max_sum = max(max_sum,prefix[i]-min_val);
            min_val = min(min_val,prefix[i]);
        }

        return max_sum;
    }
};