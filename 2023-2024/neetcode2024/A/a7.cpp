#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int zeroIndex = -1;
        int product = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroCount++;
                zeroIndex = i;
            }
            else{
                product *= nums[i];
            }
        }

        if(zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }
        if(zeroCount == 1) {
            vector<int> result(nums.size(), 0);
            result[zeroIndex] = product;
            return result;
        }
        else{
            vector<int> result(nums.size(), 0);
            for(int i = 0;i<nums.size();i++){
                result[i] = product / nums[i];
            }
            return result;
        }
    }
};
