class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        unordered_map<int,bool> mp;
        int n = 0;
        vector<vector<int>> dp(heights.size(),vector<int>());

        vector<int> res;

        for(auto q : queries){
            int q1 = q[0]; int q2 = q[1];
            
            if(q1 == q2) {res.push_back(q1); continue;}
            if(q1>q2) {int temp = q1; q1 = q2; q2 = temp;}

            int sol = -1;
            bool solFind = false;
            if(!mp[q1]){
            n++;
            for(int i = q1 + 1;i<heights.size();i++){
                if(heights[i]>heights[q1]){
                    if(n<1000)
                    dp[q1].push_back(i);
                    if(i==q2) {if(!solFind) {sol = i; solFind = true;}}
                    else if(i>q2 && heights[i]>heights[q2]){
                        if(!solFind) {sol = i; solFind = true;}
                    }
                }
            }
            if(n<1000)mp[q1] = true;
            }
            else
            for(int i : dp[q1]){
                if(i==q2) {if(!solFind) {sol = i;break;}}
                else if(i>q2 && heights[i]>heights[q2]){
                    sol = i;
                    break;
                }
            }

            res.push_back(sol);

        }
        return res;
    }
};