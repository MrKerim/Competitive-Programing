class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);

        if(total<target) return 0;

        if(n==1 && abs(nums[0]) == abs(target)) return 1;

        bool same = true;
        for(int i = 0; i<n-1;i++){
            if(nums[i]!=nums[i+1]) same = false;
        }
        if(same && nums[0]==0 && target == 0){
            return (1<<n);
        }

        if(n<6){
            for(int b = 0; b< (1<<n) ;b++){
            int subtotalRem = 0;
            for(int i = 0;i<n;i++){
                if(b&(1<<i)) subtotalRem += nums[i];
            }
            if(total - 2*subtotalRem == target) res++;

        }
            return res;
        }else{

        for(int b = 0; b< (1<<n)/2 ;b++){
            int subtotalRem = 0;
            for(int i = 0;i<n;i++){
                if(b&(1<<i)) subtotalRem += nums[i];
            }
            if(abs(total - 2*subtotalRem) == abs(target)) res++;
        }
        }


        if(target == 0 ) return 2*res;
        return res;
    }
};