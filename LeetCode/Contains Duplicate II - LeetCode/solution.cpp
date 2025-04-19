class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < nums.size();i++) mp[nums[i]].push_back(i);

        for(auto p : mp) if(p.second.size() > 1)
            for(int j = 0;j<p.second.size()-1;j++)
                if(abs(p.second[j]-p.second[j+1]) <= k) return true;

        return false;
    }
};