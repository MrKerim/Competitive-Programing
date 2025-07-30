class Solution {
public:
    int trailingZeroes(int n) {
        int twoCount = 0;
        int fiveCount = 0;
        while(n>1){
            int temp_n = n;
            while(temp_n % 2 == 0){
                twoCount++;
                temp_n = temp_n /2;
            }

            while(temp_n % 5 == 0){
                fiveCount++;
                temp_n = temp_n/5;
            }
            n--;
        }

        return min(twoCount,fiveCount);
    }
};