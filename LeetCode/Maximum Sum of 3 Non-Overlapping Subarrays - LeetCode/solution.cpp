vector<int> search(int index,int n,int count,int k, vector<int>& prefixSum,
map<pair<int,int>,vector<int> >& mp){
    // 0 - sum , byte
    //base cases
    if(index>n-k) return {0,0,0,0};
    if(count >= 3) return {0,0,0,0};

    if(!mp[make_pair(index,count)].empty()) return mp[make_pair(index,count)];

    // if we take
    vector<int> res1 = search(index+k,n,count+1,k,prefixSum,mp);
    res1[0] = res1[0] + prefixSum[index + k] - prefixSum[index];
    res1[count+1] = index; 

    vector<int> res2 = search(index+1,n,count , k,prefixSum,mp);
    // if we don't take no operation is needed

    if(res1[0]>res2[0]){
        mp[make_pair(index,count)] = res1;
        return res1;
    }
    else if(res1[0]<res2[0]){
        mp[make_pair(index,count)] = res2;
        return res2;
    }
    else {
        mp[make_pair(index,count)] = min(res1,res2);
        return min(res1,res2);
    }

}

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n+1,0);
        for(int i = 0;i<n;i++) prefixSum[i+1] = nums[i]+prefixSum[i];
        // subarray sum at index i => prefixSum[i+k-1] - prefixSum[i-1]

        map<pair<int,int>,vector<int> > mp;

        vector<int> res = search(0,n,0,k,prefixSum,mp);
        vector<int> sol;
        for(int i = 1;i<4;i++)
            sol.push_back(res[i]);

        return sol;

    }
};