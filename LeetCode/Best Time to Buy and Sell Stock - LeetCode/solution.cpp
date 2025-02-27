class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minV = prices[0];
        int res = 0;

        for(int x : prices){
            minV = min(minV,x);
            res = max(res,x-minV);
        }

        return res;
    }
};