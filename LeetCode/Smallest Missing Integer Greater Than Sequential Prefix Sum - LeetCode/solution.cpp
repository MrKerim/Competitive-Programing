class Solution {
public:
    int missingInteger(vector<int>& nums) {
        

        if(nums.size() == 1) return nums[0] + 1;
        
        unordered_map<int,int> mp;
        mp[nums[0]] = 1;
        bool fin = false;
        

        int sum = nums[0];
        for(int i = 1;i<nums.size();i++){

            mp[nums[i]] = 1;
            if(!fin &&  nums[i] == nums[i-1] + 1){
                sum+= nums[i];
                continue;
            }

            fin = true;
            
        }

        while(true){
            if(mp[sum] == 1) sum++;
            else break;
        }

        return sum;
    }
};