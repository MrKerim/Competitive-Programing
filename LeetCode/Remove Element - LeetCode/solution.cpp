class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0; int right = nums.size() - 1;
        if(right == -1) return 0;
        while(left<right){
            if(val != nums[left]){
                left++;
                continue;
            }

            // val == nums[left]
            nums[left] = nums[right];
            right--;
        }

        // left == right
        if(val != nums[left]) left++;

        return left;
    }
};