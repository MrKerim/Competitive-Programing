class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = nums.size();
        for(int i = 2;i<nums.size();i++){
            if(nums[i] == nums[i-1] && nums[i] == nums[i-2]){
            nums[i-2] = INT_MAX;
            counter--;
            }
        }
        sort(nums.begin(),nums.end());
        return counter;
    }
};