#include <iostream>
#define int long long
using namespace std;

int32_t main(){
    int k,N;cin>>k>>N;
    k++;
    int equal_int = N/k;
    int remaining = N%k;
    // N = (equal_int * k) + remaining
    cout<<(k-remaining)*(equal_int*equal_int)+remaining*(equal_int+1)*(equal_int+1)<<endl;
}