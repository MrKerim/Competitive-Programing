double recPow(double x, int n){
    if(n == 1) return x;
    double res = recPow(x,n/2);
    if(n%2 == 0) return res*res;
    return res*res*x;
}

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            if(n == -1) return 1/x;
            double res = recPow(x,abs(n/2));
            if(n%2 == 0) return 1/(res*res);
            return (1/(res*res*x));
        } 
        else return recPow(x,n);
    }
};