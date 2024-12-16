#include <iostream>
#include <cstdint>
#define int uint64_t
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return (a/gcd(a,b))*(b);
}

int32_t main(){
    int n,a,m;
    cin >> n >> a >> m;
    int x = lcm(m,a);
    cout<<(x/a)+(x/m)-1<<endl;
}