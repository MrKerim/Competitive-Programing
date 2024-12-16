class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;

        for(int i = 0; i<nums.size();i++)
            pq.push(make_pair(nums[i],i));
        
        while(k--){
            pair<int,int> p = pq.top(); pq.pop();
            p.first = p.first * multiplier;
            pq.push(p);
        }

        while(!pq.empty()){
            pair<int,int> p = pq.top(); pq.pop();
            nums[p.second] = p.first;
        }

        return nums;

    }
};