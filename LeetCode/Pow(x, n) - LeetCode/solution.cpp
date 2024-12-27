double recCal(unsigned n,double x,unordered_map<int,double>& mp){
    if(n == 1) return x;
    mp[n/2] = recCal(n/2,x,mp);
    double res = mp[n/2]*mp[n/2];
    if(n%2 == 1) res*=x;
    return res;
}

class Solution {
public:
    double myPow(double x, int n) {
    if(n == 0) return 1.0;
    if(x == 0) return 0;
    int n_sign = n < 0 ? -1 : 1; unsigned u_n =(unsigned) n* n_sign;
    int x_sign = (x/abs(x)); x = abs(x);
    bool n_even = (n%2 == 0);

    unordered_map<int,double> mp;
    double res =  recCal(u_n,x,mp);
    if(!n_even && x_sign == -1) res = -1 * res;
    if(n_sign == -1) res = 1/res;

    return res;

    }
};