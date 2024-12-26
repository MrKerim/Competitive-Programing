int search(int i,int count,vector<int>&nums){
    int max_index = -1;
    int max_val = 0; 

    for(int j = 1; i + j <nums.size() && j<=nums[i];j++){
        if(i+j == nums.size()-1) return count;
        if(i+j + nums[i+j] > max_val){
            max_val = i+j + nums[i+j];
            max_index = i+j;
        }
    }
    count++;
    return search(max_index,count,nums);
}

class Solution {
public:
    int jump(vector<int>& nums) {
        // current = i max = 0
        // for every possible jump (let jmp = i+j)
        // if i+j == n-1 -> return count
        // max = max(max,nums[i+j]+i+j) 
        // finish iterating count++;
        if(nums.size()==1) return 0;
        return search(0,1,nums);
    }
};