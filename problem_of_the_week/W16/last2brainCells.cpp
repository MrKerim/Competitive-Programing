#include <iostream>
#include <cstdint>
#define int uint64_t
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int32_t main(){
    int n,a,m;
    cin >> n >> a >> m;
    cout<<(m/gcd(m,a))+(a/gcd(m,a))-1<<endl;
}