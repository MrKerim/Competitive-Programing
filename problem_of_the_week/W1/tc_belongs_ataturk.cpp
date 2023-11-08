#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int32_t main(){

    int N;cin>>N;
    float bottom_limit = pow(N,1.0/6.0); float upper_limit = pow(N,0.2);
    int bottom_lim_int = bottom_limit; int upper_lim_int = upper_limit;

    cout<<bottom_limit<<" : "<<bottom_lim_int<<"\n"<<upper_limit<<" : "<<upper_lim_int<<endl;

    int result=0;
    bool prime[upper_lim_int+1];
    for (int i = 2; i <= upper_lim_int; i++)
    {
    if(!prime[i] && i<=bottom_lim_int){
        
        result+=i;
        prime[i]=true;
        for (int j = i+i; j <= upper_lim_int; j+=i)
        {
            if(!prime[j]){
                prime[j]=true;
            }
        }
    }
    }
    return 0;
}