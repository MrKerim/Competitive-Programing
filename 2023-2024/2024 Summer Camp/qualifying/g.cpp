#include<iostream>
#include<vector>
#include<algorithm>

int binomial(int n, int m, int k){
    int denominator = 1;
    int temp = m;
    while(temp>0){
        denominator *= (n-m*k+temp);
        temp--;
    }
    temp = 1;
    while (m--) temp *= m+1;

    return (denominator/temp)%1000000007;
}

using namespace std;
int32_t main(){

    int n,k; cin>>n>>k;
    if(n==k){
        cout<<(1<<n)%1000000007 << "\n";
        return 0;
    }
    k++;
    int sum = 0;
    for (int m = 0; m <= n/k; m++) sum+=(1-2*(m%2))*binomial(n,m,k)*((1<<(n-m*k))%1000000007)%1000000007;
    
    cout << sum%1000000007 << endl;
}