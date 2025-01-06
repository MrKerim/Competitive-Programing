class Solution {
public:
    vector<int> minOperations(string boxes) {
        int r = 0;
        int l = 0;

        vector<int> dp(boxes.length(),0);

        for(int i = 0; i<boxes.length();i++){
            dp[0] += (int(boxes[i])-48) * i;
            r+=(int(boxes[i])-48);
        }

        for(int i = 1;i<boxes.size();i++){
            r = r - int(boxes[i-1]) + 48;
            l = l + int(boxes[i-1]) - 48;

            dp[i] = dp[i-1] + l - r;
        }

        return dp;
    }
};