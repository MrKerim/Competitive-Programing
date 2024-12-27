class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int max_val = values[0];
        int max_index = 0;

        for(int i = 1;i<values.size();i++){
            res = max(res,values[i] + max_val - (i-max_index));
            if(max_val < values[i] + (i-max_index)) {
                max_val = values[i];
                max_index = i;
            }
        }
        return res;
    }
};