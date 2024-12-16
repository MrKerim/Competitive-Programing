#include <iostream>
#define int long long
#define MOD 1000000007
using namespace std;

int fac(int n){
    if(n<=0) return 1;
    return (n*fac(n-1))%MOD;
}

int32_t main(){
    int n,l; cin>>n>>l;
    if(n<=l) {cout<<0<<endl; return 0;}
    n--; int fac_n = fac(n);
    int depth_less_than_l =  (n>l)? ((fac(n+l-2)%MOD)/(fac_n*(fac(l-2)%MOD)))%MOD:0;
    // Reason for this is we have n nodes and l-1 places meaning l-2 slashes
    // So we will do permutation with repetition

    int null_trees = 0;
    for (int i = 1; i < n-1; i++)
    {
        null_trees += ((n-1-i)*(fac(n-1-i)%MOD)*(fac(i)%MOD))%MOD;
        // when i = n-2 then n_t += 1*1*(n-2)!;
    }

    cout<<(fac_n - depth_less_than_l - null_trees )%MOD<<endl;

}