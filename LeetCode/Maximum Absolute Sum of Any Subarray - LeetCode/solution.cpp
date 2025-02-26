class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int maxVal = 0;
        int minVal = 0;

        for(int x : nums){
            sum += x;
            maxVal = max(maxVal,sum);
            minVal = min(minVal,sum);
        }

        return abs(maxVal-minVal);
    }
};