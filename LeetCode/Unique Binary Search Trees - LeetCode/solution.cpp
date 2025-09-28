class Solution {
public:

        struct pair_hash {
            size_t operator()(const pair<int,int>& p) const {
                return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
            }
        };

    int search(int left,int right, unordered_map< pair<int,int>, int, pair_hash>& mp){

        pair<int,int> key = make_pair(left, right);
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        if(left == right){
            return 1;
        }

        if(left>right){
            return 1;
        }
            

        int sum = 0;

        for(int val = left; val<=right; val++) {
            sum+= ( search(left,val-1,mp) * search(val+1,right,mp) );
        }

        mp[key] = sum;
        return sum;

    }

    int numTrees(int n) {

        unordered_map< pair<int,int>, int, pair_hash> mp;

        return search(1,n,mp);

    }
};