#include <iostream>
#define int long long
#define MOD 1000000007
using namespace std;

int fac(int n){
    if(n <= 0) return 1;
    return (n * fac(n-1)%MOD) % MOD;
}

int32_t main(){
    int n,l; cin >> n >> l;
    n--; // excluding the first node
    if(n<l) {cout << 0 << endl; return 0;}
    if(n==l) {cout << 1 << endl; return 0;}
    int ans = fac(n);
    ans-= fac(n+l-2)/(ans*fac(l-2));
    for (int i = 1; i < n-1; i++) ans-= ((n-i-1)*fac(n-i-1)*fac(i))%MOD;
    
    cout << ans%MOD << endl;
    
}