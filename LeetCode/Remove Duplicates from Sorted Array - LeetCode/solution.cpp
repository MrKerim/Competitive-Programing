class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int counter = nums.size();
        for(int i = 1;i<nums.size(); i++){
            if(nums[i] != nums[i-1]) continue;
            nums[i-1] = 200;
            counter--;
        }

        sort(nums.begin(),nums.end());
        return counter;
    }
};