class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        for(int i = 0; i<n;i++){
            
            if(i-2>=0){
                dp[i] = max(
                dp[i-1]
                ,
                dp[i-2] + nums[i]
                );
            }
            else if(i-1>=0){
                dp[i] = max(dp[i-1],nums[i]);
            }
        }

        return dp[n-1];

    }
};