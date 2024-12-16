#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int> > map; // freq, number itself
        for(auto inp : nums ){
            map[inp].first++;
            map[inp].second = inp;
        }

        vector<pair<int,int>> freq;
        for(auto it: map){
            freq.push_back(make_pair(it.second.first, it.second.second));
        }

        sort(freq.begin(), freq.end(), greater<pair<int,int>>());
        vector<int> result;
        while(k--){
            result.push_back(freq[k].second);
        }
        return result;
    }   
};
