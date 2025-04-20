class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        unordered_map<int, pair<bool,bool> > mp;

        for(int n : nums){
            if(mp.count(n)) continue;
            bool before = mp.count(n-1);
            bool after = mp.count(n+1);
            mp[n] = make_pair(before,after);

            if(before) mp[n-1].second = true;
            if(after) mp[n+1].first = true;
        }

        int res = 1;

        for(auto p : mp)
        if(p.second == make_pair(0,1)){
            int current = p.first;
            int count = 1;
            while(mp[current].second != 0){
                count++;
                current++;
            }

            res = max(res,count);
        } 


        return res;
    }
};