class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0) return 0;
        int layer = ceil(log2(n));
        cout<<layer<<"\n";

        if(log2(n) == ceil(log2(n))) layer = layer+1;
        uint32_t multp = pow(2,layer-1);

        uint32_t res = 0;

        while(n>0){
            int bit = n%2;
            n = n / 2;

            res = res + bit*multp;
            multp = multp / 2;
        }


        while(32 - layer > 0){
            layer++;
            res = res * 2;
        }
        
        return res;
    }
};