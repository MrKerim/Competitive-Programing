class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        for(int x : nums)
            if(x>=target) return 1;

        if(nums.size() == 1) return 0;

        int result = INT_MAX;
        int sum = nums[0] + nums[1];
        int l = 0;
        int r = 1;

        
        while(r<nums.size()){
            if(sum>=target) {
                result = min(result,r-l+1);
                if(result == 1) return 1;
                l++;
                if(l>=r) break;
                sum -= nums[l-1];
                
            }
            else {
                r++;
                if(r<nums.size()) sum += nums[r];
                else break;
            }
        }

        if(result != INT_MAX) return result;
        else return 0;


        
    }
};