class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int sum = 0;
        for(int i = 0;i<timeSeries.size()-1;i++){
            if(timeSeries[i] + duration <= timeSeries[i+1]){
                sum += duration;
                continue;
            }

            sum+=timeSeries[i+1] - timeSeries[i];
        }

        if(timeSeries.size() == 0) return 0;
        return sum + duration;
    }
};