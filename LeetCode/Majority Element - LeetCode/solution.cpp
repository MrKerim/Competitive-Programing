class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int counter = 1;

        for(int i = 1; i<nums.size();i++){
            if(nums[i] == res) counter ++;
            else counter--;
            if(counter != 0) continue;
            counter = 1;
            res = nums[i];
        }

        return res;
    }
};