class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i<n-1;i++){
            if(nums[i] != nums[i+1]){
                
                if(nums[i] != 0) res.push_back(nums[i]);
                continue;
            }

            nums[i] = nums[i] * 2;
            nums[i+1] = 0;


            if(nums[i] != 0) res.push_back(nums[i]);

        }

        if(nums[n-1] != 0) res.push_back(nums[n-1]);

        for(int i = res.size(); i< n;i++)
            res.push_back(0);

        return res;
    }
};