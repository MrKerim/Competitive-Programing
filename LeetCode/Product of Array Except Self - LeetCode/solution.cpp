class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,1);
        vector<int> postfix(n+1,1);

        for(int i = 1;i<n;i++){
            // for i = n-1
            // p[n] = p[n-1] * n[n-2]
            // for i = 1
            // p[2] = p[1] * n[0]
            prefix[i+1] = prefix[i] * nums[i-1];
            // for i = n-1
            // p[0] = p[1] * n[1]
            // for i = 1
            // p[n-2] = p[n-1] * n[n-1]
            postfix[n -i -1] = postfix[n - i] * nums[n-i];
        }


        vector<int> res(n,0);
        for(int i = 0;i<n;i++){
            res[i] = prefix[i+1] * postfix[i];
        }

        return res;
    }
};