class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        vector<int> target(n,0);

        for(int i = 0;i<n;i++){
            target[i] = (i+1)%n;
            gas[i] = gas[i] - cost[i];
        }

        int start = 0;
        int index = start;
        while(true){
            if(gas[start]<0){
                // current value is negative go until finding positive
                int sum = 0;
                while(gas[index]<0){
                    sum+= gas[index];
                    index = target[index];
                    if(index == start) return -1;
                }
                target[start] = index;
                gas[start] = sum;

                start = index;
            }
            else{
                // if positive we go until the sum is negative 
                int sum = 0;
                while(sum>=0){
                    sum+=gas[index];
                    index = target[index];
                    if(index == start && sum >= 0) return start;
                }

                target[start] = index;
                gas[start] = sum;

                start = index;
            }
        }

        return 0;
    }
};