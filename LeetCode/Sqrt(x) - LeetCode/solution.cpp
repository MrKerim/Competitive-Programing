class Solution {
public:
    int mySqrt(int x) {

        for(int i = 0;i<100000;i++){
            if(i > x/ ((double) i) )return i-1;
        }

        return 0;

    }
};