#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int> > map;
        for(int i = 0; i<nums.size(); i++){
            if(map[nums[i]].first == 5){
                int index1 = map[nums[i]].second;
                int index2 = i;
                return index2 > index1 ? vector<int>{index1,index2} : vector<int>{index2,index1};
            }
            else map[target-nums[i]] = make_pair(5,i);
        }
    }
};
