#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int inp: nums){
            map[inp]++;
            if(map[inp]>1){
                return true;
            }
        }
        return false;
    }
};
