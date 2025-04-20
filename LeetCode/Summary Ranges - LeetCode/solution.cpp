string conv(int a,int b){
    if(a == b) return to_string(a);
    return to_string(a) + "->" + to_string(b);
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};

        vector<string> res;
        int start = nums[0];
        for(int i = 0; i<nums.size()-1;i++){
            if(nums[i+1] == nums[i]+1) continue;
            res.push_back(conv(start,nums[i]));
            start = nums[i+1];
        }
        res.push_back(conv(start,nums[nums.size()-1]));
        return res;
    }
};