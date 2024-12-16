#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int32_t main(){
    int N;cin>>N;
    double limit = pow(N,1.0/5.0); int lim_int = limit;
    int result=0;

        
    bool prime[lim_int+2];
    for (int i = 2; i <= lim_int+1; i++)
    {
    if(!prime[i]){
        if(i!=lim_int+1){
        result+=i;
        prime[i]=true;
        for (int j = i+i; j <= lim_int+1; j+=i)
        {
            if(!prime[j]){
                prime[j]=true;
            }
        }
        }
    }
    }

cout<<"result before:"<<result<<endl;

    if (lim_int == limit) cout<<result<<endl;
    else{
        if(prime[lim_int+1]){cout<<result<<endl;}
        else{
            for (int i = 1; i < lim_int; i++)
            {
                if(i*pow(lim_int,6)<=N) result+=1;
            }
            cout<<result<<endl;
        }
    }
    return 0;
}