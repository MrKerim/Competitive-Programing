class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int sum = 0;
        int minV = prices[0];

        for(int i = 1; i< prices.size();i++){
            
            if(minV > prices[i]){
                minV = prices[i];
                continue;
            }

            if(i == prices.size()-1) sum+= prices[i]-minV;
            else if(prices[i+1] > prices[i]) continue;
            else {
                sum+= prices[i]-minV;
                minV = prices[i+1];
            }

        }

        return sum;
    }
};