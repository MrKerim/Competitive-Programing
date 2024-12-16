#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        unordered_map<int,int> map;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]) continue;
            map[nums[i]]++;
            map[nums[i]+1] = map[nums[i]];
        }

        int longestConsecutive = 0;
        for(auto it: map){
            longestConsecutive = max(longestConsecutive, it.second);
        }
        return longestConsecutive;
    }
};
