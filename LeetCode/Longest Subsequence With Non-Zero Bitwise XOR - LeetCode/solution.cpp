class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        bool isNonZero = false;

        int coll = 0;
        for(int i = 0;i<nums.size(); i++){
            coll = coll ^ nums[i];
            if(nums[i] != 0) isNonZero = true;
        }

        if(coll != 0) return nums.size();
        if(!isNonZero) return 0;

        return nums.size()-1;
    }
};