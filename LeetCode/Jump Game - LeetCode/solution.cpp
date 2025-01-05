class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];
        for(int i = 0; i<nums.size();i++){
            if(i>maxIndex) return false;
            if(i == nums.size()-1) return true;

            int currentMaxInd = i + nums[i];
            if(currentMaxInd > maxIndex)
            maxIndex = currentMaxInd;
        }

        return false;
    }
};